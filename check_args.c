#include "our_shell.h"
/**
 * tokenize_input - tokenizes input strings into individual
 * arguments
 * @input_string:  input command
 *
 * Return: 1 if true
 */

char **tokenize_input(char *input_string)
{
	char *argvv = NULL, *token = NULL, *argv = NULL, *delim = " :\t\r\n\f\v";
	char **tokens = NULL;
	int j = 1;
	size_t i = 0, check = 0;
	/*start here*/
	argv = _strdup(input_string);
	if (!argv)
		return (NULL);
	argvv = argv;
	while (*argvv)
	{
		if (_strchr(delim, *argvv) != NULL && check == 0)
		{
			j++;
			check = 1;
		}
		else if (_strchr(delim, *argvv) == NULL && check == 1)
			check = 0;
		argvv++;
	}
	tokens = malloc(sizeof(char *) * (j + 1));
	token = strtok(argv, delim);

	while (token)
	{
		tokens[i] = _strdup(token);
		if (tokens[i] == NULL)
		{
			free(tokens);
			return (NULL);
		}
		token = strtok(NULL, delim);
		i++;

	}
	tokens[i] = '\0';
	free(argv);
	return (tokens);
}
