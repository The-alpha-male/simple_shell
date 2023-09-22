#include "shell.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
/**
 * handle_signal - handle Ctrl+C signal
 * @sig: signal no.ignored
 */

void handle_signal(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n#ThisIsC$ ", 10);
}

/**
 * display_prompt - Disp shell prompt and set signal handler
 */

void display_prompt(void)
{
	if (isatty(STDIN_FILENO))
	{
		signal(SIGINT, handle_signal);

		write(STDOUT_FILENO, "\n#ThisIsC$ ", 10);
	}
}
