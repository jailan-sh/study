#include "main.h"
#include <signal.h>

/**
 * main - main function to run shell
 * @ac : number count of arguments
 * @av : string of arguments
 * @env : environment varuables
 *
 * Return: 0 always success
 */

int main(int ac, char **av, char **env)
{
	if (ac == 1 && isatty(STDIN_FILENO))
		start_shell(av, env);

	else if (ac > 1 || av == NULL)
		write(2, "Please run with no arguments\n", 29), exit(127);
	return (0);
}
