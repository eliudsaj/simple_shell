#include "our_shell.h"

/**
 * show_prompt -function that prints #cisfun$
 * Return: null
 */
void show_prompt(void)
{
	if ((isatty(STDIN_FILENO) == 1) && (isatty(STDOUT_FILENO) == 1))
		check.interactive = 1;
	if (check.interactive)
		write(STDERR_FILENO, "#cisfun$ ", 9);
}
