void execute_command(char *path, char **av, char **env)
{
	pid_t pid;

	pid = fork();
	if (pid == ERROR)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		execve(path, av, env);
		perror("execve");
		exit(EXIT_FAILURE);
	}
	else if (pid > 0)
	{
		wait(NULL);
	}
}
