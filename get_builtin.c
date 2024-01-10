#include "main.h"
#include <stdio.h>

/**
 * get_builtin - Writing a builtin that pais the command in the arg
 * @cmd: command
 *
 * Return: function pointer of the builtin command
 */

int (*get_builtin(char *cmd))(data_shell *)
{
	builtin_t builtin[] = {
		{ "env", _env },
		{ "exit", exit_shell },
		{ "setenv", _setenv },
		{ "unsetenv", _unsetenv },
		{ "cd", cd_shell },
		{ "help", get_help },
		{ NULL, NULL }
	};
	int w;

	for (w = 0; builtin[w].name; w++)
	{
		if (_strcmp(builtin[w].name, cmd) == 0)
			break;
	}

	return (builtin[w].f);
}
