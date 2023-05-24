#include "main.h"

/**
 * handle_and - perform and operator on commands (i.e &&)
 * @my_env: shell's environment variables
 * @tokens: an array of pointers to commands
 * @original_path: environment path
 * @status: hold the last return value
 *
 * Return: the return value of handle_or
 */
int handle_and(char **my_env, char **tokens, char *original_path, int *status)
{
	char *and_arr[100] = {"", NULL}, *and;
	int j, k, _val, option = 0;

	j = 0;
	while (tokens[j])
	{
		k = 0;
		and = strtok(tokens[j], "&&");
		while (and)
		{
			and_arr[k] = and;
			and = strtok(NULL, "&&");
			k++;
		}
		and_arr[k] = NULL;

		_val = handle_or(my_env, and_arr, original_path, status, &option);

		j++;
	}
	return (_val);
}
