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
	char *lineptr = NULL, *path;
	char *fullpath;
	int builtin_status, flag, child_status;
	ssize_t nread;
	size_t n = 0;
	char **argument;


	signal(SIGINT, handler);

	while (1)
	{
		write(1, "shell$ ", 7);
		nread = getline(&lineptr, &n, stdin);
		if (nread == -1)
		{
			write(1, "\n", 1);
			free(lineptr), exit(EXIT_FAILURE);
		}
		if (*lineptr != '\n')
		{
			argument = tokenizer(lineptr);
			if (argument[0] == NULL)
			continue;
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
