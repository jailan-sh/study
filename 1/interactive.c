#include "main.h"

/**
 * split_line - split a string into tokens
 * @line: the string to be split
 * @delim: the delimiter characters
 *
 * Return: an array of tokens
 */
char **split_line(char *line, const char *delim)
{
    int bufsize = 64;
    int i = 0;
    char **tokens = malloc(bufsize * sizeof(char *));
    char *token;

    if (!tokens)
    {
        fprintf(stderr, "allocation error in split_line: tokens\n");
        exit(EXIT_FAILURE);
    }

    token = strtok(line, delim);
    while (token != NULL)
    {
        /* handle comments */
        if (token[0] == '#')
        {
            break;
        }
        tokens[i] = token;
        i++;
        if (i >= bufsize)
        {
            bufsize += bufsize;
            tokens = realloc(tokens, bufsize * sizeof(char *));
            if (!tokens)
            {
                fprintf(stderr, "reallocation error in split_line: tokens");
                exit(EXIT_FAILURE);
            }
        }
        token = strtok(NULL, delim);
    }
    tokens[i] = NULL;
    return (tokens);
}

/**
 * start_shell - the UNIX command line interpreter.
 * @av : pass arguments
 * @env : path
 *
 * Return: void
 */
void start_shell(char **av, char **env)
{
    char *lineptr = NULL;
    size_t n = 0;
    ssize_t nread;
    char **tokens;

    while (1)
    {
        if (isatty(STDIN_FILENO))
            printf("simple_shell$ ");
        nread = getline(&lineptr, &n, stdin);
        if (nread == -1)
        {
            write(1, "\n", 2);
            free(lineptr), exit(EXIT_FAILURE);
        }

        if (*lineptr != '\n')
        {
            tokens = split_line(lineptr, " \t\n\r");
            if (tokens != NULL && _strcmp("exit", tokens[0]) == 0)
                free(tokens);
		    break;
            execute_command(tokens, env, av);
        }
    }
    free(lineptr);
}
