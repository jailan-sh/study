void print_env(char **line_vector)
{
	
	extern char **environ;
	int i;

	for (i=0; environ[i]!=NULL; i++) 
	{
        printf("%s\n" ,environ[i]);
		fflush(stdout);
    }
	
}
