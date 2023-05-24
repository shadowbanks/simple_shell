#include "main.c"

/**
 * main - Shell program
 * @ac: argument counter
 * @av: argument variable
 * @env: environment variable
 *
 * Return: 0 (on success)
 i */
int main(int ac, char **av, char **env)
{
	int i = 0, status = 0, a = 1, j = 0;
	char *original_path, *pmt = "# ", status_str[10];
	char *my_env[100];


	void(ac);
	void(av);

	while (env[j])
	{
		my_env[j] = malloc(_strlen(env[j]) * sizeof(char) + 1);
		if (my_env[j] == NULL)
			return (-1);
		_strcpy(my_env[j], env[j]);
		j++;
	}
	my_env[j] = NULL;
	original_path = _getenv(my_env, "PATH");
	_setenv(my_env, "OLDPWD", "", 1);

	while (a)
	{
		base_conv(status_str, status, 10);
		_setenv(my_env, "?", status_str, 1);
		/*Is this fine????*/
		if (isatty(STDIN_FILENO))
			write(1, pmt, 2);
		i = prompt(my_env, original_path, &status);
		if (i == 1)
			continue;
		else if (i == 7)
			a = 0;
		else
			a = 0;
	}

	j = 0;
	while (my_env[j])
		free(my_env[j++]);
	write(1, "\n", 1);
	return (status);
}
