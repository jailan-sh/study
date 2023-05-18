#include "main.h"

void execute_command(char** argument, char** env, char* av[]) {
    pid_t child;
    int status;

    child = fork();
    if (child == -1)
    {
        free(argument), exit(EXIT_FAILURE);
    }
    if (child == 0)
    {
        if (execve(argument[0], argument, env) == -1)
            printf("%s: No such file or directory\n", av[0]);
    }
    else
    {
        wait(&status);
    }
}
