#include "main.h"

/**
 */

int main(int argc, char *argv[])
{
	FILE *fp;
       size_t n = 0;
	char *buffer = NULL;
	char *command, *arg = NULL;
	unsigned int line_number = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n"), exit(EXIT_FAILURE);
	}
	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		fprintf(stderr,"Error open file %s\n", argv[1]), exit (EXIT_FAILURE);
	}
	while (getline(&buffer, &n ,fp) != -1)
	{
		line_number++;
		command = strtok(buffer, " \n"), arg = strtok(NULL, " ");
		if (strcmp(buffer, "\n") == 0 || strncmp(command, "#", 1) == 0)
			continue;







		else (getline ==  -1)
	{
		fprintf(stderr,"Error reading input\n"), free(lineptr);
		exit (EXIT_FAILURE);
	}

	fclose(fp);
		free(lineptr);
	return (0);
}
