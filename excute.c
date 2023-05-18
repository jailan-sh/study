#include "main.h"

/**
 * excute_file - function to excute command
 * @arg : arg[0] command
 * @av : command arguments
 * @env : environment varuables
 *
 * Return: 0 success
 */

int execute_command(char *arg, char **av, char **env)
{
	pid_t child;
	int status;

	pid = fork();
	if (child == -1)
	{
		return (-1);
	}
	if (child == 0)
	{
		execve(arg, av, env);
		perror("execve");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(&status);
	}
	return (0);
}
