#include "main.h"

/**
 * handle_cd_dash - handle cd if a directory is passed
 * @my_env: environment variable
 * @prev: temp previous directory
 * @prev_dir: previous directory
 * @dir_temp: an array
 *
 * Return: 9
 */
int handle_cd_dash(char **my_env, char *prev, char *prev_dir, char *dir_temp)
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
	return (9);
}

/**
 * handle_cd_dir - handle cd if a directory is passed
 * @my_env: environment variable
 * @prev: temp previous directory
 * @prev_dir: previous directory
 * @dir_temp: an array
 *
 * Return: 9
 */
int handle_cd_dir(char **my_env, char *prev, char *prev_dir, char *dir_temp)
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

	return (9);
}
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
		return (handle_cd_dash(my_env, prev, prev_dir, dir_temp));
	else
		return (handle_cd_dir(my_env, prev, prev_dir, dir_temp));
}
