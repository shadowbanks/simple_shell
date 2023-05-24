#include "main.h"

/**
 * handle_or - perform "or" operator on commands (i.e ||)
 * @my_env: shell's environment variables
 * @tok: an array of pointers to commands
 * @org_path: environment path
 * @status: hold the last return value
 * @opt: if 1 its an "or" if 0 its an "and"
 *
 * Return: the return value of handle_args
 */
int handle_or(char **my_env, char **tok, char *org_path, int *status, int *opt)
{
	char *or_arr[100] = {"", NULL}, *or;
	int j, k, _val;

	j = 0;
	while (tok[j])
	{
		k = 0;
		or = strtok(tok[j], "||");
		while (or)
		{
			or_arr[k] = or;
			or = strtok(NULL, "||");
			k++;
		}
		or_arr[k] = NULL;

		if (k > 1)
			*opt = 1;
		_val = handle_args(my_env, or_arr, org_path, status, opt);

		if (*opt == 0 && *status != 0)
			return (_val);

		j++;
	}
	return (_val);
}
