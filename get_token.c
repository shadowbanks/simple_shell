#include "main.h"

/**
 * get_token - split the user input into commands (i.e ;)
 * @my_env: shell's environment variables
 * @lineptr: user input
 * @original_path: environment path
 * @status: hold the last return value
 *
 * Return: the return value of handle_and
 */
int get_token(char **my_env, char *lineptr, char *original_path, int *status)
{
	char *token1 = NULL, *tokens[50];
	int i = 0;

	token1 = _strtok(lineptr, ";");
	while (token1)
	{
		tokens[i] = token1;
		token1 = _strtok(NULL, ";");
		i++;
	}
	tokens[i] = NULL;

	return (handle_and(my_env, tokens, original_path, status));
}
