#include "main.h"

/**
 */

int execute_builtin_command(char **argument)
{
    if (argument == NULL || argument[0] == NULL)
    {
        return 0;
    }
    else if (argument[1] != NULL &&
             _strcmp("echo", argument[0]) == 0 && _strcmp("$$", argument[1]) == 0)
    {
        _echo();
        return 0;
    }
    else if (_strcmp("env", argument[0]) == 0)
    {
        print_env();
        return 0;
    }
    else if (_strcmp(argument[0], "exit") == 0)
    {
        exit(0);
    }
    else if (_strcmp(argument[0], "#") == 0)
    {
        return 0;
    }
    else if (_strcmp("cd", argument[0]) == 0)
    {
        my_cd(argument);
        return 0;
    }
    else
    {
        return 1;
    }
}

