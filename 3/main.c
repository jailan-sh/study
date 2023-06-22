#include "monty.h"

glob_t glob = {NULL, NULL, NULL, NULL, 0};

/**
 * main - main function
 * @argc : argument count
 * @argv : argument vector
 *
 * Return: 0 always success
 */

int main(int argc, char *argv[])
{
	FILE *fp = NULL;
	size_t n = 0;
	char *command = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n"), exit(EXIT_FAILURE);
	}
	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error open file %s\n", argv[1]), exit(EXIT_FAILURE);
	}
	glob.fp = fp;
	while (getline(&glob.line, &n, glob.fp) != -1)
	{
		glob.line_number++;
		command = strtok(glob.line, " \n\t");
		if (command != NULL && command[0] != '#')
		{
			glob.n = strtok(NULL, " \n\t");
			get_function(command);
		}
		if (glob.line != NULL)
			free(glob.line);
		glob.line = NULL;
	       command = NULL, glob.n = NULL;
	}
	free_monty();
	return (0);
}
