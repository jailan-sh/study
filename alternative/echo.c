#include "main.h"
/**
 * _echo - function echo
 *
 * @av: list of arguments
 *
 * Return: 0
 */
int _echo(char **av)
{
	int pid;

	if (av[2])
		write(2, "Too many arguments\n", 20);
	else
	{
		if (_strcmp("$$", av[1]) == 0)
		{
			pid = getpid();
			printf("%i\n", pid);
		}
		else
			printf("%s\n", av[1]);
	}
	return (0);
}
