#include "shell.h"
#include <stdlib.h>
#include <string.h>

/**
 * exe_command - checks if 1st element of array is NULL
 * @args: pointer to a args
 * @environment: pointer to a pointer
 * Return: (1) SUCCESS
 */

int exe_command(char **args, char **environment)
{
	pid_t pid;
	int status;

	if (args[0] == NULL)
	{
		return (1);
	}

	if (is_built_in(args[0])
			{
			if strcmp(args[0], "exit") == 0
			{
				handle_exit();
			} else if (strcmp(args[0], "env") == 0)
			{
				handle_environmnet();
			}
			return (1);
	}

	pid = fork();
	if (pid == 0)
	{

		execvp(args[0], args);

		perror("execvp");
		exit(EXIT_FAILURE);
	} else if (pid < 0)
	{
		perrors("fork");
	} else
	{
		do {
			status = waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	return (1);
