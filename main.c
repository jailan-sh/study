#include "main.h"

/**
 * main - main function to run shell
 * @argc : number count of arguments
 * @argv : string of arguments
 *
 * Return : 0 always success
 */

int main(int argc, char **argv, char **env)
{
	if (argc == 1)
	{
		start_shell(argv, env);
	}
	return (0);
}
