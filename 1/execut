#include "main.h"
/**
 * execute_command - execution process
 * @argument : command
 * @env : environment
 * @av : arg veector
 *
 * Return : void
 */

void execute_command(char **argument, char **env, char *av[])
{
	pid_t child_pid;
	int child_status;
	char *command_path;
	if (argument == NULL || argument[0] == NULL)
	{
		return;
	}
	else if (_strcmp("echo", argument[0]) == 0 && _strcmp("$$", argument[1]) == 0)
	{
		_echo();
		return;
	}
	else if (_strcmp("env", argument[0]) == 0)
	{
		print_env();
		return;
	}
	else if (_strcmp(argument[0], "exit") == 0)
	{
		exit(0);
	}
	else if (_strcmp(argument[0], "#") == 0)
	{
		return;
	}
	else if (_strcmp("cd", argument[0]) == 0)
                        {
                                my_cd(argument);
				return;
                        }

	command_path = which_like(argument[0]);
	if (command_path == NULL)
	{
		if (errno == ENOENT)
		{
			fprintf(stderr, "%s: %s: command not found\n", av[0], argument[0]);
		}
		else
		{
			perror(av[0]);
		}
		return;
	}
	child_pid = fork();
	if (child_pid == -1)
	{
		perror("fork");
		free(argument), exit(EXIT_FAILURE);
	}
	if (child_pid == 0)
	{
		if (execve(command_path, argument, env) == -1)
		{
				perror(av[0]);
				exit(errno);
		}
	}
	else
	{
		waitpid(child_pid, &child_status, WUNTRACED);
	}

free(command_path);
}
