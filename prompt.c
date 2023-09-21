#include "shell.h"
#include <unistd.h>
/**
 * display_prompt - Display shell prompt.
 * Display shell pront
 */

void display_prompt(void)
{
	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, "$ ", 2);
	}
}
