#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "shell.h"
/**
 * userinput - tokenizing args
 * @str: -str to be tokenized
 * Return: - a pointer array
 */
char **userinput(char *str)
{
	char **args;
	int i;
	char *tkns;
	const char *delimitor = " \n\t\r";

	i = 0;
	args = malloc(sizeof(char *) * 300);

	if (!args)
		return (NULL);
	tkns = strtok(str, delimitor);
	while (tkns)
	{
		args[i] = strdup(tkns);
		if (!args[i])
		{
			if (args)
			{
				for (i = 0; args[i] != NULL; i++)
					free(args[i]);

				free(args);
			}
			return (NULL);
		}
		tkns = strtok(NULL, delimitor);
		i++;
	}
	args[i] = NULL;
	return (args);
}
