#include "shell.h"

/**
 * main - Entry point for the shell program.
 *
 * This function initializes the shell and enters a loop to read commands,
 * parse them, and execute them until the user decides to exit.
 *
 * Return: Always returns 0.
 */
int main(void)
{
	char *line;
	char **args;
	int status;

	do {
		display_prompt();
		line = read_line();
		args = parse_line(line);
		status = execute_command(args);

		free(line);
		free(args);
	} while (status);

	return (0);
}

