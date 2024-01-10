#include "main.h"
#include <stdio.h>

/**
 * without_comment - Writing a fxn that deletes comments from the input
 *
 * @in: input string
 * Return: input without comments
 */

char *without_comment(char *in)
{
	int w, up_to;

	up_to = 0;
	for (w = 0; in[w]; w++)
	{
		if (in[w] == '#')
		{
			if (w == 0)
			{
				free(in);
				return (NULL);
			}

			if (in[w - 1] == ' ' || in[w - 1] == '\t' || in[w - 1] == ';')
				up_to = w;
		}
	}

	if (up_to != 0)
	{
		in = _realloc(in, w, up_to + 1);
		in[up_to] = '\0';
	}

	return (in);
}

/**
 * shell_loop - Writing the Loop of shell
 * @datash: data relevant (av, input, args)
 *
 * Return: no return.
 */

void shell_loop(data_shell *datash)
{
	int loop, i_eof;
	char *input;

	loop = 1;
	while (loop == 1)
	{
		write(STDIN_FILENO, "^-^ ", 4);
		input = read_line(&i_eof);
		if (i_eof != -1)
		{
			input = without_comment(input);
			if (input == NULL)
				continue;

			if (check_syntax_error(datash, input) == 1)
			{
				datash->status = 2;
				free(input);
				continue;
			}
			input = rep_var(input, datash);
			loop = split_commands(datash, input);
			datash->counter += 1;
			free(input);
		}
		else
		{
			loop = 0;
			free(input);
		}
	}
}
