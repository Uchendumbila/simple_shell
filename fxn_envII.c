#include "main.h"
#include <stdio.h>

/**
 * copy_info - Writing a fxn that copies info to create
 * a new env or alias
 * @name: name (env or alias)
 * @value: value (env or alias)
 *
 * Return: new env or alias.
 */

char *copy_info(char *name, char *value)
{
	char *new;
	int len_name, len_value, len;

	len_name = _strlen(name);
	len_value = _strlen(value);
	len = len_name + len_value + 2;
	new = malloc(sizeof(char) * (len));
	_strcpy(new, name);
	_strcat(new, "=");
	_strcat(new, value);
	_strcat(new, "\0");

	return (new);
}

/**
 * set_env - Writing a fxn that sets an environment variable
 *
 * @name: name of the environment variable
 * @value: value of the environment variable
 * @datash: data structure (environ)
 *
 * Return: no return
 */

void set_env(char *name, char *value, data_shell *datash)
{
	int w;
	char *var_env, *name_env;

	for (w = 0; datash->_environ[w]; w++)
	{
		var_env = _strdup(datash->_environ[w]);
		name_env = _strtok(var_env, "=");
		if (_strcmp(name_env, name) == 0)
		{
			free(datash->_environ[w]);
			datash->_environ[w] = copy_info(name_env, value);
			free(var_env);
			return;
		}
		free(var_env);
	}

	datash->_environ = _reallocdp(datash->_environ, w, sizeof(char *) * (w + 2));
	datash->_environ[w] = copy_info(name, value);
	datash->_environ[w + 1] = NULL;
}

/**
 * _setenv - Writing a fxn that compares env variables names
 * with the name passed.
 * @datash: data relevant (env name and env value)
 *
 * Return: 1 on success.
 */

int _setenv(data_shell *datash)
{

	if (datash->args[1] == NULL || datash->args[2] == NULL)
	{
		get_error(datash, -1);
		return (1);
	}

	set_env(datash->args[1], datash->args[2], datash);

	return (1);
}

/**
 * _unsetenv - Writing a fxn that deletes a environment variable
 *
 * @datash: data relevant (env name)
 *
 * Return: 1 on success.
 */

int _unsetenv(data_shell *datash)
{
	char **realloc_environ;
	char *var_env, *name_env;
	int w, m, n;

	if (datash->args[1] == NULL)
	{
		get_error(datash, -1);
		return (1);
	}
	n = -1;
	for (w = 0; datash->_environ[w]; w++)
	{
		var_env = _strdup(datash->_environ[w]);
		name_env = _strtok(var_env, "=");
		if (_strcmp(name_env, datash->args[1]) == 0)
		{
			n = w;
		}
		free(var_env);
	}
	if (n == -1)
	{
		get_error(datash, -1);
		return (1);
	}
	realloc_environ = malloc(sizeof(char *) * (w));
	for (w = m = 0; datash->_environ[w]; w++)
	{
		if (w != n)
		{
			realloc_environ[m] = datash->_environ[w];
			m++;
		}
	}
	realloc_environ[m] = NULL;
	free(datash->_environ[n]);
	free(datash->_environ);
	datash->_environ = realloc_environ;
	return (1);
}
