#include "main.h"

/**
 * start_shell - the UNIX command line interpreter.
 * @av : pass arguments
 * @env : path
 *
 * Return: void
 */

void non_interactive(char **av, char **env)
{
	char *lineptr = NULL, *delim = " \t\n\r";
	int i = 0;
	char *argument[MAX_ARGU];

	while (1)
	{
		lineptr  = _getline();
		if (lineptr == NULL)
		{
			free(lineptr), exit(0);
		}
		if (*lineptr != '\n')
		{
			i = 0;
			argument[i] = _strtok(lineptr, delim);
			if (_strcmp("exit", argument[0]) == 0)
				break;
			while (argument[i])
				argument[++i] = _strtok(NULL, delim);
			if (search_path_non(argument[0]) != NULL)
			{
				execute_non(argument);
			}
			else
			{
				execute_command_non(argument, env, av);
			}
		}
	}
	free(lineptr);
}
