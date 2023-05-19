#include "main.h"

/**
 * read_input - to read input by user
 * @lineptr : command input
 * @n : number of char readed
 *
 * Return: void
 */

void read_input(char **lineptr, size_t *n)
{
	ssize_t char_num;

	char_num = getline(lineptr, n, stdin);
	if (char_num == -1)
	{
		write(1, "\n", 1);
		exit(EXIT_FAILURE);
	}
}
