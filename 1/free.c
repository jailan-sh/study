#include "main.h"

/**
 */

void free_all(char *path, char *line, char *fullpath, int flag)
{
	free(path);
	free(line);
	if (flag == 1)
		free(fullpath);
}
