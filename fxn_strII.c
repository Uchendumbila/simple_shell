#include "main.h"
#include <stdio.h>

/**
 * _strdup - Writing a fxn tha duplicates a str in the heap memory.
 * @s: Type char pointer str
 *
 * Return: duplicated str
 */

char *_strdup(const char *s)
{
	char *new;
	size_t len;

	len = _strlen(s);
	new = malloc(sizeof(char) * (len + 1));
	if (new == NULL)
		return (NULL);
	_memcpy(new, s, len + 1);
	return (new);
}

/**
 * _strlen - Writing a fxn tha Returns the lenght of a string.
 * @s: Type char pointer
 *
 * Return: Always 0.
 */

int _strlen(const char *s)
{
	int len;

	for (len = 0; s[len] != 0; len++)
	{
	}
	return (len);
}

/**
 * cmp_chars - Writing a fxn that compare chars of strings
 * @str: input string.
 * @delim: delimiter.
 *
 * Return: 1 if are equals, 0 if not.
 */

int cmp_chars(char str[], const char *delim)
{
	unsigned int w, m, n;

	for (w = 0, n = 0; str[w]; w++)
	{
		for (m = 0; delim[m]; m++)
		{
			if (str[w] == delim[m])
			{
				n++;
				break;
			}
		}
	}
	if (w == n)
		return (1);
	return (0);
}

/**
 * _strtok - Writing a fxn that splits a string by some delimiter.
 * @str: input string.
 * @delim: delimiter.
 *
 * Return: string splited.
 */

char *_strtok(char str[], const char *delim)
{
	static char *splitted, *str_end;
	char *str_start;
	unsigned int w, bool;

	if (str != NULL)
	{
		if (cmp_chars(str, delim))
			return (NULL);
		splitted = str; /*Store first address*/
		w = _strlen(str);
		str_end = &str[w]; /*Store last address*/
	}
	str_start = splitted;
	if (str_start == str_end) /*Reaching the end*/
		return (NULL);

	for (bool = 0; *splitted; splitted++)
	{
		/*Breaking loop finding the next token*/
		if (splitted != str_start)
			if (*splitted && *(splitted - 1) == '\0')
				break;
		/*Replacing delimiter for null char*/
		for (w = 0; delim[w]; w++)
		{
			if (*splitted == delim[w])
			{
				*splitted = '\0';
				if (splitted == str_start)
					str_start++;
				break;
			}
		}
		if (bool == 0 && *splitted) /*Str != Delim*/
			bool = 1;
	}
	if (bool == 0) /*Str == Delim*/
		return (NULL);
	return (str_start);
}

/**
 * _isdigit - Writing a fxn that defines if string passed is a number
 *
 * @s: input string
 *
 * Return: 1 if string is a number. 0 in other case.
 */

int _isdigit(const char *s)
{
	unsigned int w;

	for (w = 0; s[w]; w++)
	{
		if (s[w] < 48 || s[w] > 57)
			return (0);
	}
	return (1);
}
