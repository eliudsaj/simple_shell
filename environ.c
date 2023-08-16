#include "our_shell.h"

char *_getenv(void);
char *locate_cmd(char *cmd, char *input_string);
char *check_path(char **cmd, char *av);

/**
* locate_cmd - locates the path from the environment
* @cmd: path of command
* @input_string: user entered command
*
* Return: the path of the command
*/
char *locate_cmd(char *cmd, char *input_string)
{
	char *path_buff;
	size_t i = 0, j = 0;
	/*this space didi not pass betty test*/
	if (input_string == 0)
		input_string = "";
	if (cmd == 0)
		cmd = "";
	path_buff = malloc(sizeof(char) * (_strlen(cmd) + _strlen(input_string) + 2));
	/* the 2 in to include a '/' character and a '\0' character */
	if (path_buff == 0)
		return (NULL);
	/*
	 * we copy token obtained to a new file 'new_path' then
	 * we append '/' and '\0'
	 */
	while (cmd[i])
	{
		/*copy cmd to path_buff*/
		path_buff[i] = cmd[i];
		i++;
	}
	if (cmd[i - 1] != '/')
	{
		path_buff[i] = '/';
		i++;
	}
	while (input_string[j])
	{
		path_buff[i + j] = input_string[j];
		j++;
	}
	path_buff[i + j] = '\0';
	return (path_buff);
}

/**
 * check_path -checks if the path is a builtin command
 * @cmd: path that has been split
 * @av: the string entered by user
 * Return: null
 */

char *check_path(char **cmd, char *av)
{
	int i = 0;
	char *path;
	/*this space did not pass betty test*/
	while (cmd[i])
	{
		path = locate_cmd(cmd[i], av);
		if (access(path, X_OK | F_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	return (NULL);
}

/**
 * _getenv - finds path
 * Return: the path if found
 */

char *_getenv(void)
{
	int i;
	char **env = environ;
	char *path = NULL;
	/*search for PATH environment variable in the list of environ*/
	while (*env)
	{
		if (_strncmp(*env, "PATH=", 5) == 0)
			/**
			 * 5 represents the length of 'PATH='
			 * this is done to check if the current environment variable in the
			 * list is the PATH variable, which begins with the string "PATH=".
			 */
		{
			path = *env;
			while (*path && i < 5)
			{
				path++;
				i++;
			}
			return (path);
		}
		env++;
	}
	return (NULL);
}

