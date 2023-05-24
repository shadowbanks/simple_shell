#include "main"

/**
 * handle_args - handle individual command and it's arguments
 * @my_env: shell's environment variables
 * @_ar: an array of pointers to command and it's arguments
 * @org_path: environment path
 * @stat: hold the last return value
 * @opt: if 1 its an "or" if 0 its an "and"
 *
 * Return: 99 (signify cd), *stat(holds execute return)
 *
 */
int handle_args(char **my_env, char **_ar, char *org_path, int *stat, int *opt)
{
	char *argv[100] = {"", NULL};
	int k;

	k = 0;
	while (_ar[k])
	{
		split_args(_ar, argv, k);

		if (_strcmp(argv[0], "exit") == 0)
		{
			if (argv[1])
				*stat = (atoi(argv[1]));
			return (99);
		}


		if (_strcmp(argv[0], "cd") == 0)
		{
			if (handle_cd(my_env, argv) == 9)
				break;
		}
		exe_command(argv, org_path, stat);
		if (*stat == -1)
			break;

		if (*opt == 0)
		{
			if (*stat != 0)
				return (*stat);
		}
		else if (*opt == 1)
		{
			if (*stat == 0)
				return (*stat);
		}

		k++;
	}
	return (*stat);
}
