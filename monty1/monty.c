#include "main.h"

/**
 */

int main(int argc, char *argv[])
{
	FILE *fp;
	ssize_t nread;
       size_t n = 0;
	char *lineptr = NULL;
	char *tokens;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n"), exit(EXIT_FAILURE);
	}
	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		fprintf(stderr,"Error open file %s\n", argv[1]), exit (EXIT_FAILURE);
	}
	nread = getline(&lineptr, &n ,fp);
	if (nread == -1)
	{
		fprintf(stderr,"Error reading input\n"), free(lineptr);
		exit (EXIT_FAILURE);
	}
	else
	{
		token = strtok(lineptr, " \n\t");
		while 

	fclose(fp);
		free(lineptr);
	return (0);
}
