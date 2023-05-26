#include "main.h"

void handle_env(char **my_env)
{
	int i = 0;

	while (my_env[i] != NULL)
	{
		write(1, my_env[i], _strlen(my_env[i]));
		write(1, "\n", 1);
		i++;
	}
}

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
void handle_exit(char **my_env, char **argv, int *stat)
{
	if (argv[1])
	{
		if (argv[1][0] < '0' || argv[1][0] > '9')
			handle_err(my_env, argv[0], "Illegal number");
		else if (argv[1])
			*stat = atoi(argv[1]);
		else
			handle_err(my_env, argv[0], "Illegal number");
	}
}
int handle_args(char **my_env, char **_ar, char *org_path, int *stat, int *opt)
{
	char *argv[100] = {"", NULL};
	int k = 0;

	while (_ar[k])
	{
		if (split_args(_ar, argv, k) == 32)
		{
			*stat = 0;
			return (99);
		}

		if (_strcmp(argv[0], "exit") == 0)
		{
			handle_exit(my_env, argv, stat);
			return (99);
		}

		if (_strcmp(argv[0], "cd") == 0)
		{
			if (handle_cd(my_env, argv) == 9)
				break;
		}
		if (_strcmp(argv[0], "env") == 0)
		{
			handle_env(my_env);
			return(99);
		}
		exe_command(my_env, argv, org_path, stat);
		if (*stat == -1)
			break;

		if (ret_stat(opt, stat) == 1)
			return (*stat);
		k++;
	}
	return (*stat);
}

/**
 * ret_stat - for && and || to know if to break or continue
 * @opt: option
 * @status: status
 *
 * Return: 1 (to break), 0 (to continue)
 */
int ret_stat(int *opt, int *stat)
{
	if (*opt == 0)
	{
		if (*stat != 0)
			return (1);
	}
	else if (*opt == 1)
	{
		if (*stat == 0)
			return (1);
	}
	return (0);
}
