#include "our_shell.h"

void _signal(int n);

/**
 * main - displays a prompt and wait for the user to type a command
 * @av: argument supplied
 * @env: enviroment command
 * @ac: argument count
 * Return: 0 on success
 */

int main(int ac, char **av, char *env[])
{
	char *input_string = NULL, *cmd_path = NULL, *path = NULL;
	size_t buff_size = 0;
	int i = 0;
	ssize_t num_char = 0;
	char **tokens = NULL, **cmd = NULL;
	(void)env, (void)av;
	/*start here*/
	if (ac < 1)
		return (-1);
	signal(SIGINT, _signal);
	while (1)
	{
		free_mem(cmd);
		free_mem(tokens);
		free(cmd_path);
		/*prompt user for input*/
		show_prompt();
		/*read input from user using getline*/
		num_char = getline(&input_string, &buff_size, stdin);
		if (num_char == -1)
		{
			break;
		}
		while (input_string[i])
		{
			if (input_string[i] == '\n')
				input_string[i] = '\0';
			i++;
		}
		cmd = tokenize_input(input_string);
		if (cmd[0] == NULL || cmd[0][0] == '\0' || cmd == NULL)
			continue;
		/*check for builtin commands*/
		if (my_path(cmd, input_string))
			continue;
		/*look for commands in the directories listed in the path environment*/
		path = _getenv();
		tokens = tokenize_input(path);
		cmd_path = check_path(tokens, cmd[0]);
		if (cmd_path == 0)
			perror(av[0]);
		else
			exec_cmd(cmd_path, cmd);
	}
	if (num_char == -1 && check.interactive)
		write(STDERR_FILENO, "\n", 1);
	free(input_string);
	return (0);
}

/**
 * _signal - maintains a record of shell running in interactive mode
 * @n: signal number
 */

void _signal(int n)
{
	(void)n;
	write(STDERR_FILENO, "\n", 1);
	write(STDERR_FILENO, "$", 2);
}
