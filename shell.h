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
int execute_command(char *arguments, char **args_array);
int built_in_cmd(char *command);
void handle_exit(void);
void handle_environment(void);
void environment_printf(void);
char *find_location(const char *cmd);
int exe_command(char **args);
extern char **environ;
char **userinput(char *str);
ssize_t get_user_line(char *cpt_inpt, size_t buffer_size, char **line, size_t *n);
#endif
