#ifndef MAIN_h_
#define MAIN_h_

#define MAX_ARGU 128

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


void start_shell(char **av, char **env);
int execute_command(char *arg, char **av, char **env);
char *which_like(char *command);
char *check_syscommand(char *str);
int path_check(char *str);

#endif
