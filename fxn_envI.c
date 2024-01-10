#include "main.h"
#include <stdio.h>

/**
 * cmp_env_name - Writing a fxn that compares env variables names
 * with the name passed.
 * @nenv: name of the environment variable
 * @name: name passed
 *
 * Return: 0 if are not equal. Another value if they are.
 */

int cmp_env_name(const char *nenv, const char *name)
{
	int w;

	for (w = 0; nenv[w] != '='; w++)
	{
		if (nenv[w] != name[w])
		{
			return (0);
		}
	}

	return (w + 1);
}

/**
 * _getenv - Writing a fxn that gets an environment variable
 * @name: name of the environment variable
 * @_environ: environment variable
 *
 * Return: value of the environment variable if is found.
 * In other case, returns NULL.
 */

char *_getenv(const char *name, char **_environ)
{
	char *ptr_env;
	int w, mov;

	/* Initialize ptr_env value */
	ptr_env = NULL;
	mov = 0;
	/* Compare all environment variables */
	/* environ is declared in the header file */
	for (w = 0; _environ[w]; w++)
	{
		/* If name and env are equal */
		mov = cmp_env_name(_environ[w], name);
		if (mov)
		{
			ptr_env = _environ[w];
			break;
		}
	}

	return (ptr_env + mov);
}

/**
 * _env - Writing a fxn that prints the evironment variables
 *
 * @datash: data relevant.
 *
 * Return: 1 on success.
 */

int _env(data_shell *datash)
{
	int w, m;

	for (w = 0; datash->_environ[w]; w++)
	{

		for (m = 0; datash->_environ[w][m]; m++)
			;

		write(STDOUT_FILENO, datash->_environ[w], m);
		write(STDOUT_FILENO, "\n", 1);
	}
	datash->status = 0;

	return (1);
}
