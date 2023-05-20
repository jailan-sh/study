#include "main.h"
/**
 * _echo - function echo
 *
 * @av: list of arguments
 *
 * Return: 0
 */
void _echo(char **av)
{
	int pid;
	
	if (strcmp("$$", av[1]) == 0)
	{
	
		pid = getpid();
		printf("%i\n", pid);
	}
	
	else
		return;
}
