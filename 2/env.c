#include "main.h"

/**
 *
 */
void print_env(char **argv)
{
	int i;

	for (i=0; environ[i]!=NULL; i++)
	{
        printf("%s\n" ,environ[i]);
		fflush(stdout);
    }

}

int check_mode(int argc)
{
	if(argc == 1)
		return (INTERACTIVE);
	else if(argc == 2)
		return (NON_INTERACTIVE);
	return (-1);
}

char* get_status(int n)
{
	char *status;
	status = num_to_char(n);
	return status;

}

char* get_process_id()
{
	char *ppid_s;
	pid_t pid = getpid();

	ppid_s = num_to_char(pid);

	return (ppid_s);
}
