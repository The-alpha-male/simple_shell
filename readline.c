#include "shell.h"
#include <string.h>

/**
 * read_line - Read a line of input from the user.
 *
 * This function reads a line of input from the standard input (stdin).
 *
 * Return: A pointer to the dynamically allocated string containing the
 *         input line, or NULL on failure.
 */
char *read_line(void)
{
	char *line = NULL;
	size_t bufsize = 0;
	ssize_t read;

	read = getline(&line, &bufsize, stdin);
	if (read == -1)
	{
		if (feof(stdin))
		{
			printf("\n");
			exit(0); /* Handle Ctrl+D */
		}
		else
		{
			perror("getline");
			exit(EXIT_FAILURE);
		}
	}

	/* Remove the trailing newline character */
	if (line[read - 1] == '\n')
		line[read - 1] = '\0';

	return (line);
}

