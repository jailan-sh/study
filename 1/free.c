#include "main.h"

/**
 */

void free_all(char **argument,char *path, char *line, char *fullpath, int flag)
{
	free(path);
	free(line);
	free(argument);
	if (flag == 1)
		free(fullpath);
}

/**
 * free_dp - free double pointer
 * @array: double pointer to free
 * @length: length of double pointer
 * Return: void
 */
void free_dp(char **array, unsigned int length)
{
	unsigned int i;

	i = 0;
	while (i < length)
	{
		free(array[i]);
		i++;
	}
	free(array);
}
