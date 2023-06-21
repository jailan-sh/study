#include "main.h"

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
	char *buffer, *command, *arg = NULL;
	stack_t *head = NULL;
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

	nread = getline(&buffer, &n ,fp);
	if (nread == -1)
	{
		fprintf(stderr,"Error reading input\n"), free(lineptr);
		exit (EXIT_FAILURE);
	}
	while (nread >= 0)
	{
		line_number++;
		command = strtok(buffer, " \n");
		if (strcmp(buffer, "\n") != 0 || strncmp(command, "#", 1) != 0)
		{
			arg = strtok(NULL, " ");
			*get_function(command)(&head, line_number);
		}
		nread = getline(&buffer, &n ,fp);
		command = NULL, arg = NULL;
	}
	fclose(fp);
		free(buffer);
		free(fp);
	return (0);
}
