#include "main.h"

int non_interactive(char **my_env, char *original_path, int *status);

/**
 * main - Shell program
 * @ac: argument counter
 * @av: argument variable
 * @env: environment variable
 *
 * Return: 0 (on success)
 */
int main(int ac, char **av, char **env)
{
	int i = 0, status = 0, a = 1, j = 0;
	char *original_path, *pmt = "# ", status_str[10];
	char *my_env[100];

	if (ac < 0 || av == NULL)
		return (-1);

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

	if (isatty(STDIN_FILENO))
	{
		while (a)
		{
			base_conv(status_str, status, 10);
			_setenv(my_env, "?", status_str, 1);

			write(1, pmt, 2);
			i = prompt(my_env, original_path, &status);
			if (i == 1)
				continue;
			else if (i == 7)
				a = 0;
			else
				a = 0;
		}
	}
	else
	{
		if (non_interactive(my_env, original_path, &status) == -1)
			return (status);
	}

	j = 0;
	while (my_env[j])
		free(my_env[j++]);
	return (status);
}

/**
 * non_interactive - Handle non-interactive mode
 * @my_env: shell environment variable
 * @original_path: environment path
 * @status: hold the last return value
 *
 * Return: -1 (on failure), 0 (success)
 */
int non_interactive(char **my_env, char *original_path, int *status)
{
	size_t line_size = 0;
	char *line = NULL, status_str[10];
	ssize_t read;

	while ((read = _getline(&line, &line_size, stdin)) > 0)
	{
		base_conv(status_str, *status, 10);
		_setenv(my_env, "?", status_str, 1);
		if (line[read - 1] == '\n')
			line[read - 1] = '\0';
		if (get_token(my_env, line, original_path, status) == 99)
		{
			free(line);
			return (-1);
		}
	}
	free(line);
	return (0);
}
