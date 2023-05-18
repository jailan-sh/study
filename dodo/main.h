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

void execute(char **argv);
char *which_like(char *command);
char *_getenv(const char *var);
void exit_shell();
int is_builtin(char **argv);
char *_memset(char *s, char b, unsigned int n);
char *_memcpy(char *dest, char *src, unsigned int n);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
int _getline(char **buffer, size_t *bufsize, int fd);
#endif
