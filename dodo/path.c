#include "main.h"

/**
 * which_like - get path of the command
 *
 * Return: path if exist or NULL if not
 * @command : command entered by user
 */
char *which_like(char *command)
{
	char *path, *path_cp, *path_token, *file_path;
	int command_len, directory_len;
	struct stat buff;

	path = _getenv("PATH");
	if (path)
	{
		path_cp = strdup(path);
		command_len = strlen(command);
		path_token = strtok(path_cp, ":");
		while (path_token != NULL)
		{
			directory_len = strlen(path_token);
			file_path = malloc(command_len + directory_len + 2);
			strcpy(file_path, path_token);
			strcat(file_path, "/");
			strcat(file_path, command);
			strcat(file_path, "\0");
			if (stat(file_path, &buff) == 0)
			{
				free(path_cp);
				return (file_path);
			}
			else
			{
				free(file_path);
				path_token = strtok(NULL, ":");
			}
		}
	free(path_cp);
	if (stat(command, &buff) == 0)
	{
		return (command);
	}
	return (NULL);
	}
	return (NULL);
}

char *_getenv(const char *name)
{
    int i = 0, j = 0;
    extern char **environ;

    if (name == NULL)
        return (NULL);
    while (environ[i])
    {
        j = 0;
        while (environ[i][j] != '=')
        {
            if (environ[i][j] != name[j])
                break;
            if (environ[i][j] == name[j] && (environ[i][j + 1] == '='))
                return (&environ[i][strlen(name) + 1]);
            j++;
        }
        i++;
    }
    return (NULL);
}
