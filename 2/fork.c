#include "main.h"

/**
 * fork_process - fork process to child and parent
 * @path : command argv[0]
 * @av : argument of command
 * @env : environment variable
 *
 * Return: void
 */

void fork_process(char **arg, char **env)
{
	pid_t child;
	int status;

	child = fork();
	if (child == -1)
	{
		free(arg);
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (child == 0)
	{
		if (execve(arg[0], arg, env) == -1)
		perror("execve");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(&status);
	}
}
