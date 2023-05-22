#include "main.h"

/**
 * start_shell - the UNIX command line interpreter.
 * @av : pass arguments
 * @env : path
 *
 * Return: void
 */

void start_shell(char **av, char **env)
{
	char *lineptr = NULL, *delim = " \t\n\r";
	size_t n = 0;
	int i = 0;
	ssize_t nread;
	char *argument[MAX_ARGU];

	signal(SIGINT, handler);
	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(1, "shell$ ", 7);
		nread = getline(&lineptr, &n, stdin);
		if (nread == -1)
		{
			write(1, "\n", 1);
			free(lineptr), exit(EXIT_FAILURE);
		}
		if (*lineptr != '\n')
		{
			i = 0;
			argument[i] = _strtok(lineptr, delim);

			while (argument[i])
			{
				if (i > 0 && argument[i] != NULL && _strcmp(argument[i], "#") == 0)
				{
					argument[i] = '\0';
				}
				argument[++i] = _strtok(NULL, delim);
			}
			execute_command(argument, env, av);
		}
	}
	free(lineptr);
}
