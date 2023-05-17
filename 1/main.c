#include "main.h"

/**
 * main - main function to run shell
 * @argc : number count of arguments
 * @argv : string of arguments
 *
 * Return : 0 always success
 */

int main(int ac, char **av, char **env)
{
	if (ac == 1)
		start_shell(av, env);
	return (0);
}
