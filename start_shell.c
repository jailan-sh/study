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
	char *lineptr = NULL, *delim = " ", *end = "exit";
	size_t n = 0;
	int status, i = 0;
	ssize_t nread;
	char *argument[MAX_ARGU];
	pid_t child;

	while (1)
	{
		if (isatty(STDIN_FILENO))
		printf("simple_shell$ ");
		nread = getline(&lineptr, &n, stdin);
		if (nread == -1)
		{
			free(lineptr), exit(EXIT_FAILURE);
		}
		if (*lineptr != '\n')
		{
		i = 0;
		while (lineptr[i])
		{
			if (lineptr[i] == '\n')
				lineptr[i] = 0;
			i++;
		}
		i = 0;
		argument[i] = strtok(lineptr, delim);
		if (strcmp(end, argument[0]) == 0)
			break;
		while (argument[i])
			argument[++i] = strtok(NULL, delim);

		child = fork();
		if (child == -1)
		{
			free(lineptr), exit(EXIT_FAILURE);
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
	}
}
