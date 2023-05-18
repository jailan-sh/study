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
	char *lineptr = NULL, *delim = " \t\n\r", *end = "exit";
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
			write(1, "\n", 2);
			free(lineptr), exit(0);
		}
		if (*lineptr != '\n')
		{
		i = 0;
		argument[i] = strtok(lineptr, delim);
		if (strcmp(end, argument[0]) == 0)
			break;
		while (argument[i])
			argument[++i] = strtok(NULL, delim);
		if (execute_command(argument[0], argument, env) == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
			/**printf("%s: No such file or directory\n", av[0]);*/
		}
	}
}
