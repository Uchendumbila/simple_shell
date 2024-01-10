#include "main.h"
#include <stdio.h>

/**
 * rev_string - Writing a fxn that reverses a string.
 * @s: input string.
 *
 * Return: no return.
 */

void rev_string(char *s)
{
	int count = 0, w, m;
	char *str, temp;

	while (count >= 0)
	{
		if (s[count] == '\0')
			break;
		count++;
	}
	str = s;

	for (w = 0; w < (count - 1); w++)
	{
		for (m = w + 1; m > 0; m--)
		{
			temp = *(str + m);
			*(str + m) = *(str + (m - 1));
			*(str + (m - 1)) = temp;
		}
	}
}
