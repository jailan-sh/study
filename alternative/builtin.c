#include "main.h"

/**
 * checkBuiltins - Check for built in commands
 * @av: Argument to check
 * @buff: buffer
 * @count: count
 * Return: 0 success, 1 not found
 */

int checkBuiltins(char **av, char *buff, int count)
{

	if (av && *av && buff)
	{
		if (_strcmp("env", av[0]) == 0 && _strlen(av[0]) == 3)
		{
			print_env();
			return (0);
		}
		else if (_strcmp("exit", av[0]) == 0 && _strlen(av[0]) == 4)
			return (2);
		else if (_strcmp("cd", av[0]) == 0 && _strlen(av[0]) == 2)
		{
			_cd(av, count);
			return (0);
		}
		else if (_strcmp("help", av[0]) == 0 && _strlen(av[0]) == 4)
		{
			_help(av);
			return (0);
		}
		else if (_strcmp("echo", av[0]) == 0 && _strlen(av[0]) == 4)
		{
			_echo(av);
			return (0);
		}
	}
	return (1);
}

/**
 * print_env - Print the environnment
 *
 * Return: Void
 */

/**
 * print_env - function to print environment
 *
 * Return: void
 */

void print_env(void)
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
