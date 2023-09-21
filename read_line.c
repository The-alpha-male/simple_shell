#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "shell.h"

#define BUFFER_SIZE 1024
/**
 * get_user_line - reads user inputs
 * @line: p tp that stores the buffer
 * @n: size of the buffer
 * @cpt_inpt: line to read
 * @buffer_size: size storing the cpt_inpt
 * Return: num of char read
 */
ssize_t get_user_line(char *cpt_inpt,
		size_t buffer_size, char **line, size_t *n)
{
	static char buffer[BUFFER_SIZE];
	static size_t cb_pos, cb_size;
	size_t nw_pos, len_line, x, y, newsize;
	char *newrine;

	for (y = 0; y < buffer_size && cpt_inpt[y] != '\0'; y++)
		buffer[y] = cpt_inpt[y];
	cb_pos = 0;
	cb_size = buffer_size;
	len_line = 0;
	nw_pos = cd_pos;

	while (nw_pos < cb_size && buffer[nw_pos] != '\n')
		nw_pos++;
	len_line = nw_pos - cb_pos;
	newsize = len_line + 1;
	newrine = malloc(newsize);

	if (newline == NULL)
		return (-1);

	for (x = 0; x < len_line; x++)
	{
		newrine[x] = buffer[cb_pos + x];
	}

	newrine[len_line] = '\0';
	free(*line);

	*line = newrine;
	*n = newsize - 1;
	cb_pos = nw_pos + 1;

	return (len_line);
}
