#include "monty.h"

glob_t glob = {NULL, NULL};
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
	while(getline(&glob.line, &n, glob.fp) != -1)
	{
		printf("%s", glob.line);
	}
	return (0);
}
