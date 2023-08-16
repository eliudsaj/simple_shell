#include "our_shell.h"

/**
 * exec_cmd - executes commands entered by users
 * @cmd: command
 * @av: vector array of pointers to commands
 * Return: 0
 */
void exec_cmd(char *cmd, char **av)
{
	pid_t child_process;
	int status;
	char **env = environ;
	/* Create a new process to run the command */
	child_process = fork();
	if (child_process == -1)
	{
		perror(cmd);
	}
	else if (child_process == 0)
	{
		/* Child process: execute the command */
		execve(cmd, av, env);
		perror(cmd);
		free(cmd);
		free_mem(av);
		exit(98);
	}
	else
	{
		/* Parent process: wait for child to complete */
		wait(&status);
	}
}
