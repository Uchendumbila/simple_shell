#include "main.h"
#include <stdio.h>

/**
 * get_sigint - Writing a fxn that handles the crtl + c call in prompt
 * @sig: Signal handler
 */
void get_sigint(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n^-^ ", 5);
}
