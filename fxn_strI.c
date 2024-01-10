#include "main.h"
#include <stdio.h>

/**
 * _strcat - Writing a fxn that concatenates two strings
 * @dest: char pointer the dest of the copied str
 * @src: const char pointer the source of str
 *
 * Return: the dest
 */

char *_strcat(char *dest, const char *src)
{
	int w;
	int m;

	for (w = 0; dest[w] != '\0'; w++)
		;

	for (m = 0; src[m] != '\0'; m++)
	{
		dest[w] = src[m];
		w++;
	}

	dest[w] = '\0';
	return (dest);
}

/**
 * *_strcpy - Writing a fxn that Copies the string pointed to by src.
 * @dest: Type char pointer the dest of the copied str
 * @src: Type char pointer the source of str
 *
 * Return: the dest.
 */

char *_strcpy(char *dest, char *src)
{

	size_t b;

	for (b = 0; src[b] != '\0'; b++)
	{
		dest[b] = src[b];
	}
	dest[b] = '\0';

	return (dest);
}

/**
 * _strcmp - Writing a fxn that compares two strings.
 * @s1: type str compared
 * @s2: type str compared
 *
 * Return: Always 0.
 */

int _strcmp(char *s1, char *s2)
{
	int w;

	for (w = 0; s1[w] == s2[w] && s1[w]; w++)
		;

	if (s1[w] > s2[w])
		return (1);
	if (s1[w] < s2[w])
		return (-1);
	return (0);
}

/**
 * _strchr - Writing a fxn that locates a character in a string,
 * @s: string.
 * @c: character.
 *
 * Return: the pointer to the first occurrence of the character c.
 */

char *_strchr(char *s, char c)
{
	unsigned int w = 0;

	for (; *(s + w) != '\0'; w++)
		if (*(s + w) == c)
			return (s + w);
	if (*(s + w) == c)
		return (s + w);
	return ('\0');
}

/**
 * _strspn - Writing a fxn that gets the length of a prefix substring.
 * @s: initial segment.
 * @accept: accepted bytes.
 *
 * Return: the number of accepted bytes.
 */

int _strspn(char *s, char *accept)
{
	int w, m, bool;

	for (w = 0; *(s + w) != '\0'; w++)
	{
		bool = 1;
		for (m = 0; *(accept + m) != '\0'; m++)
		{
			if (*(s + w) == *(accept + m))
			{
				bool = 0;
				break;
			}
		}
		if (bool == 1)
			break;
	}
	return (w);
}
