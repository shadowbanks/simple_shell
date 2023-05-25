#include "main.h"

/**
 * handle_cd - Handles cd (change directory command)
 * @my_env: shell's environment variables
 * @argv: array of pointers holding directory
 *
 * Return: 9
 */
int handle_cd(char **my_env, char **argv)
{
	char *dir = NULL, dir_temp[100] = "", *prev;

	if (argv[1])
		dir = argv[1];
	if (!dir)
		dir = "/home";
	if (_strcmp(dir, "-") == 0)
	{
		prev = _getenv(my_env, "OLDPWD");
		if (_strlen(prev) != 0)
		{
			if (getcwd(dir_temp, sizeof(dir_temp)) == NULL)
				perror("Error");
			if (chdir(prev) != 0)
			{
				perror("Error");
				return (9);
			}
			_setenv(my_env, "PWD", dir_temp, 1);
			_setenv(my_env, "OLDPWD", dir_temp, 1);
		}
		else
		{
			write(2, "cd: OLDPWD not set\n", 19);
			return (9);
		}
	}
	else
	{
		if (getcwd(dir_temp, sizeof(dir_temp)) == NULL)
			perror("Error");
		if (chdir(dir) != 0)
		{
			perror("Error");
			return (9);
		}
		_setenv(my_env, "PWD", dir_temp, 1);
		_setenv(my_env, "OLDPWD", dir_temp, 1);
	}
	return (9);
}
