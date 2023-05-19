#include "main.h"

/**
 * execute_command - excute commands
 * @argv : array command
 *
 * Return: void
 */

void execute_command(char **argv)
{
	pid_t child;

	if (strcmp("exit", argv[0]) == 0)
	{
		exit_shell();
	}
	child = fork();
	if (child == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (child == 0)
	{
		execute(argv);
		printf("%s: No such file or directory\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}
}

/**
 * cleanup - free memory
 * @argv : array command
 * @lineptr : readed
 * @lineptr_copy : copy of lineptr
 *
 * Return: void
 */

void cleanup(char **argv, char *lineptr, char *lineptr_copy)
{
	free(argv);
	free(lineptr_copy);
	free(lineptr);
}
