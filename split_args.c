#include "main.h"

/**
 * split_args - Split command and it's argument
 * @tokens: array of pointers to commands
 * @argv: holds the split command from it's argument
 * @k: command position
 *
 * Return: pointer to commands and arguments
 */
char **split_args(char **tokens, char **argv, int k)
{
	char *token;
	int i;

	i = 0;
	token = strtok(tokens[k], " ");

	while (token)
	{
		argv[i] = token;
		token = strtok(NULL, " ");
		i++;
	}
	argv[i] = NULL;

	return (argv);
}
