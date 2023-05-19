#include "main.h"

/**
 * parse_input - to divid command into tokens
 * @line : command
 * @delim : string containing the delimiters.
 * @token_num : tokens count
 *
 * Return: tokens
 */

char **parse_input(char *line, const char *delim, int *token_num)
{
	char *token;
	char **argv;
	int i;
	char *line_copy;
	size_t n = strlen(line) + 1;
	*token_num = 0;
	line_copy = malloc(sizeof(char) * n);
	if (line_copy == NULL)
	{
		exit(EXIT_FAILURE);
	}
	strcpy(line_copy, line);
	token = strtok(line, delim);
	while (token != NULL)
	{
		(*token_num)++;
		token = strtok(NULL, delim);
	}
	(*token_num)++;
	argv = malloc(sizeof(char *) * (*token_num));
	token = strtok(line_copy, delim);
	for (i = 0; token != NULL; i++)
	{
		argv[i] = malloc(sizeof(char) * strlen(token));
		if (argv[i] == NULL)
		{
			perror("memory allocation error\n");
			exit(EXIT_FAILURE);
		}
		strcpy(argv[i], token);
		token = strtok(NULL, delim);
	}
	argv[i] = NULL;
	return (argv);
}
