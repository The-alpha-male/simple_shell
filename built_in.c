#include "shell.h"
#include <string.h>

/**
 * built_in_cmd - checks if command is in-built
 * @command: pointer to a char
 * Return: (1) if command is in-built
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
	exit(0);
}

/**
 * handle_environment - show environment variables to the standard output
 * @environment: pointer to a char pointer
 */

void handle_environment(char **environment)
{
	char **env = environment;

	while (*env)
	{
		printf("%s\n", *env);
		env++;
	}
}
