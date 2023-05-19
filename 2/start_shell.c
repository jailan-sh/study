#include "main.h"

/**
 * start_shell - the UNIX command line interpreter.
 * @av : pass arguments
 * @env : path
 *
 * Return: void
 */

int main(int argc, char **argv, char **env)
{
	char *ptr, *nc;
	size_t n = 0;
	int pt, inbt;
	ssize_t nread;
	char *argument[MAX_ARGU];

	if (argc > 1)
		argv[1] = NULL;

	while (1)
	{
		if (isatty(STDIN_FILENO))
		printf("simple_shell$ ");
		nread = getline(&ptr, &n, stdin);
		if (nread == -1)
		{
			write (1,"\n",2);
			free(ptr), exit(EXIT_FAILURE);
		}
		if (*ptr != '\n')
		{
			
		if (strcmp("exit", argument[0]) == 0)
			break;
		inbt = buildin(argument[0]);
		nc = filecheck(argument[0]);
		if (inbt == 0 && nc != NULL)
			argument[0] = nc;
		pt = pathcheck(argument[0]);
		if (pt == 1)
			fork_process(argument, env);
		if (nc == NULL, pt == 0, inbt == 0)
			printf("%s: No such file or directory\n", av[0]);
		}
	}
	free(nc);
}
