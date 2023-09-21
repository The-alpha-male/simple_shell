#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdbool.h>
#include "shell.h"

#define BUFFER_SIZE 1024
/**
 * main - entry to the shell
 * @argc: len of args
 * @argv: array of argments
 * Return: 0 for success
 */
int main(int argc, char **argv)
{
	char **args = argv;
	ssize_t sts;
	char *buffer = NULL;
	ssize len;
	int i;

	while (1)
	{
		display_prompt();
		sts = getline(&buffer, &len, stdin);
		if (sts == -1)
		{
			free(buffer);
			exit(0);
		}
		args = userinput(buffer);
		if (args == NULL)
			continue;
		exe_command(args[0], args);
		for (i = 0, args[i] != NULL; i++)
			free(args[i]);
		free(args);
		free(buffer);
		len = 0;
		buffer = NULL;
	}
	if (args)
	{
		for (i = 0; args[i] != NULL; i++)
		{
			free(args[i]);
		}
		free(args);
	}
	return (0);
	argc++;
}
