#include "main.h"

glob_v glob
void set_glob(void);

/**
 * main - main function
 * @argc : argument count
 * @argv : argument vector
 *
 * @Return: 0 always success
 */

int main(int argc, char *argv[])
{
	FILE *fp;
	size_t n = 0;
	ssize_t nread;
	char *buffer, *command = NULL;
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
	glob.fp =fp;
	set_glob();
	nread = getline(&buffer, &n ,glob.fp);
	glob.buff = buffer;
	if (nread == -1)
	{
		fprintf(stderr,"Error reading input\n"), free(lineptr);
		exit (EXIT_FAILURE);
	}
	while (nread >= 0)
	{
		glob.line_number++;
		command = strtok(glob.buff, " \n\t");
		if (strcmp(buffer, "\n") != 0 || strncmp(command, "#", 1) != 0)
		{
			glob.n = strtok(NULL, " ");
			get_function(command);
		}
		nread = getline(&buffer, &n, glob.fp);
		command = NULL, glob.n = NULL;
	}
	fclose(glob.fp);
	free(glob.buff);
	free(glob.head);
	return (0);
}

/**
 * set_glob - set global variables
 *
 * Return: void
 */

void set_glob(void)
{
	glob.buff = NULL;
	glob.n = NULL;
	glob.head = NULL;
	glob.line_number = 0;
}
