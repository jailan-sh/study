#ifndef MAIN_h_
#define MAIN_h_

#define MAX_ARGU 1024

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

#define ERR_MALLOC "Unable to malloc space\n"
#define ERR_FORK "Unable to fork and create child process\n"
#define ERR_PATH "No such file or directory\n"

extern char **environ;

/** prompt*/
void non_interactive(char **av, char **env);
void start_shell(void);
char *which_like(char *command);
int execute_builtin_command(char **argument);
void execute_external_command(char **argument, char **env, char *av[]);
char *_which(char *command, char *fullpath, char *path);
void free_all(char **argument, char *path, char *line, char *fullpath, int flag);
int child(char *fullpath, char **tokens);
void errors(int error);
char *_getenv(const char *name);
char **copy_env(char **environ_copy, unsigned int environ_length);
void free_dp(char **array, unsigned int length);
int child(char *fullpath, char **tokens);
char **tokenizer(char *str);
/**string functions */

char *_strcpy(char *dest, char *src);
int _strlen(char *s);
char *_strncat(char *dest, char *src, int n);
int _strcmp(char *s1, char *s2);
unsigned int _strspn(char *s, char *accept);
char *_strdup(char *str);
void _puts(char *s);
char *_strcat(char *dest, char *src);
int _strncmp(char *name, char *variable, unsigned int length);


/**implement functions*/

char *_strtok(char *line, char *delim);
char *_getline(void);
char *_getenv(const char *name);
void _puts(char *s);

/**builtin commands*/

void print_env(void);
void _echo(void);
int my_cd(char **argument);
void handler(int sig __attribute__((unused)));


#endif
