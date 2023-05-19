#include "main.h"

/**
 * main - strart shell
 * @ac : count
 * @argv : command input
 *
 * Return: 0 always success
 */

int main(int ac, char **argv)
{
	char *shell_prompt = "our_shell$ ";
	char *lineptr = NULL, *lineptr_copy = NULL;
	size_t n = 0;
	const char *delim = " \n";
	int token_num;
	int interactive_mode = isatty(STDIN_FILENO);
	(void)ac;
	if (interactive_mode)
	{
		while (1)
		{
			write(1, shell_prompt, strlen(shell_prompt));
			read_input(&lineptr, &n);
			if  (*lineptr != '\n')
			{
			lineptr_copy = strdup(lineptr);
			argv = parse_input(lineptr, delim, &token_num);
			execute_command(argv);
			}
		}
	}
	cleanup(argv, lineptr, lineptr_copy);
	return (0);
}
