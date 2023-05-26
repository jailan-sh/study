#include "main.h"

/**
 */

void noninteractive(int argc, char *argv[])
{
	char *line, *path, *fullpath;
	char **tokens;
	int flag, builtin_status, child_status;

	fullpath = NULL;
	if (argc > 1)
	{
		freopen(argv[1], "r", stdin);
	}
	while ((line = _getline(stdin)) != NULL)
	{
		if (_strcmp(line, "\n", 1) == 0)
		{
			free(line);
			continue;
		}
		tokens = tokenizer(line);
		builtin_status = execute_builtin_command(tokens);
		if (builtin_status == 0 || builtin_status == -1)
		{
			free(tokens), free(line);
		}
		if (builtin_status == 0)
			continue;
		if (builtin_status == -1)
			_exit(EXIT_SUCCESS);
		flag = 0;
		path = _getenv("PATH");
		fullpath = _which(tokens[0], fullpath, path);
		if (fullpath == NULL)
			fullpath = tokens[0];
		else
			flag = 1;
		child_status = child(fullpath, tokens);
		if (child_status == -1)
			errors(2);
		free_all(tokens, path, line, fullpath, flag);
	}
}
