#include "main.h"

/**
 * _setenv - Set or replace an envrionment "namee=value"
 * @my_env: shell environment variable
 * @name: environment name
 * @value: environment value
 * @overwrite: 0 (don't change value) else change environment value
 *
 * Return: 0 (success), 1 (fail);
 */
int _setenv(char **my_env, const char *name, const char *value, int overwrite)
{
	int i = 0, j = 0;
	char *new_env = NULL;

	new_env = malloc(_strlen(name) + _strlen(value) + 2);
	if (!new_env)
		return (1);

	while (name[i])
	{
		new_env[i] = name[i];
		i++;
	}
	new_env[i++] = '=';
	while (value[j])
	{
		new_env[i] = value[j];
		i++, j++;
	}
	new_env[i] = '\0';

	if (check_env(my_env, new_env, overwrite, name) == 1)
	{
		free(new_env);
		return (1);
	}
	return (0);
}
