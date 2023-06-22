#include "monty.h"

glob_t glob = {NULL, NULL, NULL};
/**
 * main - main function
 * @argc : argument count
 * @argv : argument vector
 *
 * Return: 0 always success
 */

int main(int argc, char *argv[])
{
	stack_t *head = NULL;
	FILE *fp = NULL;
	size_t n = 0;
	ssize_t nread;
	unsigned int line_number = 0;
	char *buffer = NULL, *command = NULL, *arg = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n"), exit(EXIT_FAILURE);
	}
	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error open file %s\n", argv[1]), exit(EXIT_FAILURE);
	}
	nread = getline(&buffer, &n, fp);
	while (nread >= 0)
	{
		line_number++;
		command = strtok(buffer, " \n\t");
		if (strcmp(buffer, "\n") != 0 || strncmp(command, "#", 1) != 0)
		{
			glob.n = strtok(NULL, " ");
			get_function(command)(&head, line_number);
		}
		nread = getline(&buffer, &n, fp);
		command = NULL, glob.n = NULL;
	}
	free_monty();
	free_dlist(head)
	return (0);
}
