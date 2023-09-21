#include "shell.h"

/**
 * display_prompt - Display shell prompt.
 * Display shell pront
 */

void display_prompt(void)
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILEO, "$ ", 2)
}
