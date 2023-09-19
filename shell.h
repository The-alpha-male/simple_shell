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
int built_in_cmd(char *command);
void handle_exit(void);
void handle_environment(void);
void handle_env(void);
int exe_command(char **args);
#endif
