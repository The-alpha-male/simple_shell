#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>

#define BUFSIZE 1024

void display_prompt(void);
char *read_line(void);
char **parse_line(char *line);
int execute_command(char **args);
int is_build_in(char *command);
void handle_exit(void);
void handle_environment(void);

#endif
