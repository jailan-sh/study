#include "main.h"

/**
 * print_env - function to print environment
 * @arg : command env
 *
 * Return: void
 */

void print_env(char **arg)
{
	unsigned int i, length;
	
	i = 0;
	while (environ[i] != NULL)
	{
		length = _strlen(environ[i]);
		write(STDOUT_FILENO, environ[i], length);
		write(STDOUT_FILENO, "\n", 1);
		i++;
		fflush(stdout);
	}
}
