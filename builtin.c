#include "our_shell.h"

/**
 * print_env - prints envronment variable
 * @env: environment variable
 */
void print_env(char **env);
void my_exit(char **cmd, char *argv);
int builtin_handle(char **cmd, char *argv);
void free_mem(char **buff);
int my_path(char **cmd, char *input);

void print_env(char **env)
{
	int environ = 0;
	/*this space did not pass betty*/
	while (env[environ] != NULL)
	{
		size_t length = strlen(env[environ]);
		/*this space did not pass betty*/
		write(STDOUT_FILENO, env[environ], length);
		write(STDOUT_FILENO, "\n", 1);
		environ++;
	}
}

/**
 * my_exit - exits the shell when entered
 * @cmd: command that is tokenized
 * @argv: input from user
 */
void my_exit(char **cmd, char *argv)
{
	free(argv);
	free_mem(cmd);
	exit(0);
}

/**
 * builtin_handle - executes builtin commands
 * @cmd: command
 * @argv: line from the user
 * Return: 1 if passed or 0
 */

int builtin_handle(char **cmd, char *argv)
{
	char **env = environ;
	struct builtin b = {"env", "exit"};
	/*this space did not pass betty*/
	if (my_strcmp(*cmd, b.env) == 0)
	{
		print_env(env);
		return (1);
	}
	else if (my_strcmp(*cmd, b.exit) == 0)
	{
		my_exit(cmd, argv);
		return (1);
	}
	return (0);
}

/**
 * free_mem - frees buffers
 * @buff: buffer to be freed
 */

void free_mem(char **buff)
{
	int i = 0;
	/*this space did not pass betty*/
	if (buff == 0 || buff == NULL)
		return;
	while (buff[i])
	{
		free(buff[i]);
		i++;
	}
	free(buff);
}
/**
 * my_path - checks if path
 * @cmd: tokeniized input
 * @input: input from user
 * Return: 1 is executed
 */
int my_path(char **cmd, char *input)
{
	if (builtin_handle(cmd, input))
		return (1);
	else if (**cmd == '/')
	{
		exec_cmd(cmd[0], cmd);
		return (1);
	}
	return (0);
}
