#include "shell.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * find_location - getting the whole path of a cmd
 * @cmd: the given command
 * Return: full path
 */

char *find_location(const char *cmd)
{
	char *tkns;
	int lnght;
	char *path_env;
	char *pathway;
	char *fullpath;
	const char *delimitor = ":";

	if (strchr(cmd, '/') != NULL)
	{
		if (access(cmd, X_OK) == 0)
			return (strdup(cmd));
		return (NULL);
	}
	path_env = getenv("PATH");
	if (!path_env)
		return (NULL);
	pathway = strdup(path_env);
	tkns = strtok(pathway, delimitor);
	while (tkns)
	{
		lnght = strlen(tkns) + strlen(cmd) + 2;
		fullpath = malloc(sizeof(char) * lnght);
		if (!fullpath)
		{
			free(pathway);
			return (NULL);
		}
		sprintf(fullpath, "%s/%s", tkns, cmd);
		if (access(fullpath, F_OK) == 0)
		{
			free(pathway);
			return (fullpath);
		}
		free(fullpath);
		tkns = strtok(NULL, delimitor);
	}
	free(pathway);
	return (NULL);
}

