#include "main.h"
#include <stdio.h>

/**
 * check_env - Writing a fxn that checks if the typed variable
 * is an env variable
 *
 * @h: head of linked list
 * @in: input string
 * @data: data structure
 * Return: no return
 */
void check_env(r_var **h, char *in, data_shell *data)
{
	int row, chr, j, lval;
	char **_envr;

	_envr = data->_environ;
	for (row = 0; _envr[row]; row++)
	{
		for (j = 1, chr = 0; _envr[row][chr]; chr++)
		{
			if (_envr[row][chr] == '=')
			{
				lval = _strlen(_envr[row] + chr + 1);
				add_rvar_node(h, j, _envr[row] + chr + 1, lval);
				return;
			}

			if (in[j] == _envr[row][chr])
				j++;
			else
				break;
		}
	}

	for (j = 0; in[j]; j++)
	{
		if (in[j] == ' ' || in[j] == '\t' || in[j] == ';' || in[j] == '\n')
			break;
	}

	add_rvar_node(h, j, NULL, 0);
}

/**
 * check_vars - Writing a fxn that checks if the typed variable is $$ or $?
 *
 * @h: head of the linked list
 * @in: input string
 * @st: last status of the Shell
 * @data: data structure
 * Return: no return
 */

int check_vars(r_var **h, char *in, char *st, data_shell *data)
{
	int w, lst, lpd;

	lst = _strlen(st);
	lpd = _strlen(data->pid);

	for (w = 0; in[w]; w++)
	{
		if (in[w] == '$')
		{
			if (in[w + 1] == '?')
				add_rvar_node(h, 2, st, lst), w++;
			else if (in[w + 1] == '$')
				add_rvar_node(h, 2, data->pid, lpd), w++;
			else if (in[w + 1] == '\n')
				add_rvar_node(h, 0, NULL, 0);
			else if (in[w + 1] == '\0')
				add_rvar_node(h, 0, NULL, 0);
			else if (in[w + 1] == ' ')
				add_rvar_node(h, 0, NULL, 0);
			else if (in[w + 1] == '\t')
				add_rvar_node(h, 0, NULL, 0);
			else if (in[w + 1] == ';')
				add_rvar_node(h, 0, NULL, 0);
			else
				check_env(h, in + w, data);
		}
	}

	return (w);
}

/**
 * replaced_input - Writing a fxn that replaces string into variables
 * @head: head of the linked list
 * @input: input string
 * @new_input: new input string (replaced)
 * @nlen: new length
 *
 * Return: replaced string
 */

char *replaced_input(r_var **head, char *input, char *new_input, int nlen)
{
	r_var *indx;
	int w, m, n;

	indx = *head;
	for (m = w = 0; w < nlen; w++)
	{
		if (input[m] == '$')
		{
			if (!(indx->len_var) && !(indx->len_val))
			{
				new_input[w] = input[m];
				m++;
			}
			else if (indx->len_var && !(indx->len_val))
			{
				for (n = 0; n < indx->len_var; n++)
					m++;
				w--;
			}
			else
			{
				for (n = 0; n < indx->len_val; n++)
				{
					new_input[w] = indx->val[n];
					w++;
				}
				m += (indx->len_var);
				w--;
			}
			indx = indx->next;
		}
		else
		{
			new_input[w] = input[m];
			m++;
		}
	}

	return (new_input);
}

/**
 * rep_var - Writing a fxn that calls functions to replace string into vars
 *
 * @input: input string
 * @datash: data structure
 *
 * Return: replaced string
 */

char *rep_var(char *input, data_shell *datash)
{
	r_var *head, *indx;
	char *status, *new_input;
	int olen, nlen;

	status = aux_itoa(datash->status);
	head = NULL;

	olen = check_vars(&head, input, status, datash);

	if (head == NULL)
	{
		free(status);
		return (input);
	}

	indx = head;
	nlen = 0;

	while (indx != NULL)
	{
		nlen += (indx->len_val - indx->len_var);
		indx = indx->next;
	}

	nlen += olen;

	new_input = malloc(sizeof(char) * (nlen + 1));
	new_input[nlen] = '\0';

	new_input = replaced_input(&head, input, new_input, nlen);

	free(input);
	free(status);
	free_rvar_list(&head);

	return (new_input);
}
