#include "shell.h"
#include <stdlib.h>
#include <string.h>

/**
 * exe_command - checks if 1st element of array is NULL
 * @args: pointer to a args
 * Return: (1) SUCCESS
 */

int exe_command(char **args)
{
	pid_t pid;
	int status;

	if (args[0] == NULL)
	{
		return (1);
	}

	if (built_in_cmd(args[0]))
	{
		if (strcmp(args[0], "exit") == 0)
		{
			handle_exit();
		} else if (strcmp(args[0], "env") == 0)
		{
			handle_env();
		}
		return (1);
	}

	pid = fork();
	if (pid == 0)
	{

		execve(args[0], args, environ);

		perror("execve");
		exit(EXIT_FAILURE);
	} else if (pid < 0)
	{
		perror("fork");
	} else
	{
		do {
			status = waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	return (1);
}

