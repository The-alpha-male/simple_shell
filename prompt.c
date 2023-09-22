#include "shell.h"
#include <unistd.h>
/**
 * display_prompt - Display shell prompt.
 * Display shell promt
 */

void display_prompt(void)
{
	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, "$", 2);
	}
}
