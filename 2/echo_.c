#include "main.h"

/**
 *
 */

int echo(char **argv)
{
	char *id;

	if (strcmp(argv[1], "$$") == 0)
	{
		id = get_pid()
	}
	else if (strcmp(argv[1], "$?") == 0)
	{
		id = get_status(status);
	}
	else
	{
		return (-1);
	}
	return (0);
}

/**
 */

char *get_pid()
{
	pid_t pid;
	char *id;

	pid = getpid();
	id = convert_num(pid);
	return (id);
}

/**
 */

char *get_status(status)
{

