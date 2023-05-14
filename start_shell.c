#include "main.h"

/**
 * start_shell - the UNIX command line interpreter.
 * @argv : pass arguments
 * @env : path
 *
 * Return: void
 */

void start_shell(char **argv, char **env)
{
	char *lineptr = NULL;
	size_t n = 0;
	int i = 0;
	int check;
	ssize_t count;
       	char *string[] = {NULL, NULL};
	pid_t pid;

	while (1)
	{
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
		pid = fork();
		if (pid == -1)
		{
			free(lineptr);
			exit(EXIT_FAILURE);
		}
		if (pid == 0)
		{
			check = execve(string[0], string, env);
			if (check == -1)
			{
				printf("%s: No such file or directory\n", argv[0]);
			}
		}
		else
		{
			wait(NULL);
		}
	}
}



