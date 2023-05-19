#include "main.h"

/**
 * print_env - function to print environment
 * @arg : command env
 *
 * Return: void
 */

void print_env(char **arg)
{
	int i;
	
	for (i=0; environ[i]!=NULL; i++)
	{
		printf("%s\n" ,environ[i]);
		fflush(stdout);
	}
}
