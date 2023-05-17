#include "main.h"

/**
 * fork_process - fork process to child and parent
 * @path : command argv[0]
 * @av : argument of command
 * @env : environment variable
 *
 * Return: void
 */

void fork_process(char *path, char **av, char **env)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		execve(path, av, env);
		perror("execve");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(status);
	}
}
