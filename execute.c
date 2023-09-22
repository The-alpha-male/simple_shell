#include "shell.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

/**
 * exe_command - checks if 1st element of array is NULL
 * @arguments: pointer to a args
 * @args_array: arguments container
 * Return: (1) SUCCESS
 */

int exe_command(char *arguments, char **args_array)
{
	char *cmd_path, *cmd;
	pid_t process_id;
	int sts;

	if (!args_array[0])
		return (0);
	cmd = args_array[0];
	if (strcmp(cmd, "env") == 0)
		/*print the env*/
		environment_printf();
	else if (strcmp(cmd, "exit") == 0)
	{
		handle_exit();
	}
	else
	{
		cmd_path = find_location(cmd);
		if (!cmd_path)
		{
			fprintf(stderr, "%s: No such file\n", arguments);
			return (0);
		}
		process_id = fork();
		if (process_id == -1)
			perror("Error");
		else if (process_id == 0)
		{
			if (execve(cmd_path, args_array, NULL) == -1)
			{
				perror("Error");
				exit(0);
			}
		}
		else if (wait(&sts) == -1)
			perror("Error");
		free(cmd_path);
	}
	return (0);
}
