#include "main.h"
/**
 * _echo - function echo
 *
 * @av: list of arguments
 *
 * Return: 0
 */
void _echo(char **av)
{
	int pid;
	
	if (strcmp("$$", av[1]) == 0)
	{
	
		pid = getpid();
		printf("%i\n", pid);
	}
	
	else
		return;
}


if (_strcmp(token, "$$") == 0)
			{
				int pid = getpid();
				char pid_str[16]; /*max sizeof pid*/
				int_to_str(pid, pid_str);
				command = _strdup(pid_str);
				vector[i++] = command;

			}
void int_to_str(int n, char *str)
{
	int tmp;
	int i = 0;
	if (n == 0)
	{
		str[i++] = '0';
	}
	tmp = n;
	while (tmp > 0)
	{
		tmp /= 10;
		i++; /* calc str length needed*/
	}
	tmp = n;
	while (i > 0)
	{
		str[--i] = tmp % 10 + '0'; /*store rightmost and move backward*/
		tmp /= 10; /*remove rightmost*/

	}
	str[i] = '\0'; /*null term*/

}
