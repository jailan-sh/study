#include "main.h"

/**
 * path_check - to check if function exist in path
 *@str : argument to be checked
 *
 * Return: 1 if exist , 0if not
 */

int psth_check(char *str)
{
	char *path = "/bin/", *temp, *temp2;
	int i = 0, j = 0;

	temp = malloc(sizeof(char) * 128);
	if (temp == NULL)
	{
		return (0);
	}
	while (path[i])
	{
		if (path[i] != str[i])
		{
			free(temp);
			return (0);
		}
		i++;
	}
	while (str[i])
	{
		temp[j] = str[i];
		j++;
		i++;
	}
	temp[j] = '\0';

	temp2 = check_syscommand(temp);
	if (temp2 != NULL)
	{
		free(temp);
		return (1);
	}
	return (0);
}
