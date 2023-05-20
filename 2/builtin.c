#include "main.h"

/**
 */

int checkbuiltin(char **av)
{
	if (av && *av)
	{
		if (strcmp("env", av[0]) == 0 && strlen(av[0]) == 3)
		{
			print_env();
			return (0);
		}
		else if (strcmp("cd", av[0]) == 0 && strlen(av[0]) == 2)
		{
			my_cd(av);
			return (0);
		}
		else if (strcmp("echo", av[0]) == 0 && strlen(av[0]) == 4)
		{
			_echo(av);
			return (0);
		}
	}
	return(1);
}
