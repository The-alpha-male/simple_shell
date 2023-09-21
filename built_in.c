#include "shell.h"
#include <string.h>

/**
 * built_in_cmd - checks if command is in-built
 * @command: pointer to a char
 * Return: (1) if command is in-built (0) FAIL
 */

int built_in_cmd(char *command)
{
	return (strcmp(command, "exit") == 0
	|| strcmp(command, "env") == 0);
}

/**
 * handle_exit - activates when exit command is used
 */

void handle_exit(void)
{
	char last_exit[] = "Bye You are Leaving Shell.......\n";

	write(STDOUT_FILENO, last_exit, sizeof(last_exit) - 1);
	exit(0);
}

/**
 * environment_printf - show environment variables to the standard output
 */

void environment_printf(void)
{
	char **str_var = environ;

	while (*str_var)
	{
		printf("%s\n", str_var);
		str_var++;
	}
}
