#include "shell.h"
#include <string.h>

/**
 * parse_line - Parse a line into an array of arguments.
 *
 * @line: The input line to be parsed.
 *
 * Return: An array of arguments (tokens) or NULL on failure.
 */
char **parse_line(char *line)
{
	const char delim[] = " ";
	char **args = malloc(BUFSIZE * sizeof(char *));
	char *token;
	int i = 0;

	if (!args)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, delim);
	while (token != NULL)
	{
		args[i] = strdup(token);
		if (!args[i])
		{
			perror("strdup");
			exit(EXIT_FAILURE);
		}
		token = strtok(NULL, delim);
		i++;
	}
	args[i] = NULL;
	return (args);
}

