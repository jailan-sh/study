#include "main.h"
#include <dirent.h>

/**
 * check_syscommand - for checking it is system command or buildin command
 * @str : argument to be checked
 *
 * Return: NULL if not system command to be forked
 * or command file if it is system command
 */

char *check_syscommand(char *str)
{
	char *temp1, *temp2;
	struct dirent *entry;

	DIR *dir = opendir("/bin/");

	if (dir == NULL)
		return (NULL);
	entry = readdir(dir);
	while (entry)
	{
		temp1 = entry->d_name;
		if (strcmp(temp1, str) == 0)
		{
			temp2 = strcat("/bin/", str);
			closedir(dir);
			return (temp2);
		}
		entry = readdir(dir);
	}
	closedir(dir);
	return (NULL);
}



