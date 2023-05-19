#ifndef MAIN_h_
#define MAIN_h_

#include <stddef.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>

extern char **environ;

void execute(char**argv);
char *which_like(char *command);
void exit_shell();
char *_getenv(const char *var);
int is_builtin(char **argv);
void read_input(char **lineptr, size_t *n);
char **parse_input(char *line, const char *delim, int *token_num);
void cleanup(char **argv, char *lineptr, char *lineptr_copy);
void execute_command(char **argv);


#endif
