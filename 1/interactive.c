#include "main.h"

/**
 * start_shell - the UNIX command line interpreter.
 * @av : pass arguments
 * @env : path
 *
 * Return: void
 */

void start_shell(void)
{
	char *lineptr = NULL, *delim = " \t\n\r", *path;
	char *fullpath;
	int i = 0, builtin_status, flag, child_status;
	char **argument;

argument = malloc(MAX_ARGU * sizeof(char *));
if (argument == NULL)
{
   perror("malloc");
}
    argument[i] = NULL;

	signal(SIGINT, handler);

	while (1)
	{
		write(1, "shell$ ", 7);
		lineptr  = _getline();
		if (lineptr == NULL)
		{
			write(1, "exit\n", 6);
		       	exit(EXIT_FAILURE);
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
		builtin_status = execute_builtin_command(argument);
		if (builtin_status == 0 || builtin_status == 1)
		{
			free(lineptr);
		}
		if (builtin_status == 0)
			continue;
		if (builtin_status == 1)
			_exit(EXIT_SUCCESS);
		flag = 0; /* 0 if full_path is not malloc'd */
		path = _getenv("PATH");
		fullpath = _which(argument[0], fullpath, path);
		if (fullpath == NULL)
			fullpath = argument[0];
		else
			flag = 1; /* if fullpath was malloc'd, flag to free */
		child_status = child(fullpath, argument);
		if (child_status == -1)
			errors(2);
		free_all(argument, path, lineptr, fullpath, flag);
		}
	}
}
