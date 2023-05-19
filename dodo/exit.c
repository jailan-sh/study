#include "main.h"

/**
 * exit_shell - to exit shell
 *
 * Return: void
 */

void exit_shell(void)
{
	printf("Exiting shell...\n");
	fflush(stdout);
	exit(0);
}

/**
 * is_builtin - to comper and do function
 * @argv : command
 *
 * Return: 0 success
 */

int is_builtin(char **argv)
{
	return (strcmp(argv[0], "exit") == 0);
}
