#include "main.h"

/**
 * start_shell - the UNIX command line interpreter.
 * @argv : pass arguments
 * @env : path
 *
 * Return: void
 */

void start_shell(char **av, char **env)
{
	char *lineptr = NULL;
	size_t n = 0;
	int status, i = 0;
	ssize_t count;
	char *argument[] = {NULL, NULL};
	pid_t child;

	while (1)
	{
		if (isatty(STDIN_FILENO))
		printf("simple_shell$ ");
		count = getline(&lineptr, &n, stdin);
		if (count == -1)
		{
			free(lineptr);
			exit(EXIT_FAILURE);
		}
		while (lineptr[i])
		{
			if (lineptr[i] == '\n')
				lineptr[i] = 0;
			i++;
		}
		argument[0] = lineptr;
		child = fork();
		if (child == -1)
		{
			free(lineptr);
			exit(EXIT_FAILURE);
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
