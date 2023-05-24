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
	char *dir = NULL, prev[100] = "", prev_dir[100] = "", dir_temp[100] = "";

	if (argv[1])
		dir = argv[1];
	if (!dir)
		dir = "/home";
	if (_strcmp(dir, "-") == 0)
	{
		_strcpy(prev, _getenv(my_env, "OLDPWD"));
		if (_strlen(prev) != 0)
		{
			if (getcwd(prev_dir, sizeof(prev_dir)) == NULL)
				perror("Error");
			if (chdir(prev) != 0)
			{
				perror("Error");
				return (9);
			}
			if (getcwd(dir_temp, sizeof(dir_temp)) == NULL)
				perror("Error");
			_setenv(my_env, "PWD", dir_temp, 1);
			_strcpy(prev, prev_dir);
			_setenv(my_env, "OLDPWD", prev, 1);
		}
		else
		{
			printf("cd: OLDPWD not set\n");
			return (9);
		}
	}
	else
	{
		if (getcwd(prev_dir, sizeof(prev_dir)) == NULL)
			perror("Error");
		if (chdir(dir) != 0)
		{
			perror("Error");
			return (9);
		}
		if (getcwd(dir_temp, sizeof(dir_temp)) == NULL)
			perror("Error");
		_setenv(my_env, "PWD", dir_temp, 1);
		_strcpy(prev, prev_dir);
		_setenv(my_env, "OLDPWD", prev, 1);
	}

	return (9);
}
