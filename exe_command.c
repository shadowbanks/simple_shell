#include "main.h"

/**
 * handle_err - Handle error
 * @my_env - environment variable
 * @msg: error message
 *
 * Return: nothing
 */
void handle_err(char **my_env, const char *msg)
{
	char *name = _getenv(my_env, "_");
	write(2, name, _strlen(name));
	write(2, ": ", 2);
	write(2, msg, _strlen(msg));
	write(2, "\n", 1);
}

/**
 * exe_command - Start a child process and execute command
 * @my_env: environment variable
 * @argv: an array of pointers to command and it's arguments
 * @original_path: environment path
 * @status: hold the last return value
 *
 * Return: 99 (signify cd), *stat(holds execute return)
 */
int exe_command(char **my_env, char **argv, char *original_path, int *status)
{
	char *path = NULL, *command = NULL;
	pid_t cpid;

	path = _strdup(original_path); /*create a copy of the original path*/
	command = searchfile(argv, path);
	if (command)
	{
		cpid = fork(); /*start a child process*/
		if (cpid == -1)
			perror("CPID Error:");
		else if (cpid == 0)
		{
			argv[0] = command; /*assign the command read by getline*/
			if (execve(argv[0], argv, my_env) == -1)
			{
				handle_err(my_env, "No such file or directory");
				exit(1);
			}
		}
		else
		{
			wait(status);/*wait for child process to end*/
			free(command);
			free(path);
			*status = *status >>  8;
			return (*status);
		}
	}
	else
	{
		handle_err(my_env, "No such file or directory");
		free(path);
		return (-1);
	}
	free(path);
	free(command);
	return (0);
}
