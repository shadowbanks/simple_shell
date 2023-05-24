#inclde "main.h"

/**
 * exe_command - Start a child process and execute command
 * @argv: an array of pointers to command and it's arguments
 * @original_path: environment path
 * @status: hold the last return value
 *
 * Return: 99 (signify cd), *stat(holds execute return)
 */
int exe_command(char **argv, char *original_path, int *status)
{
	char *path = NULL, *command = NULL;
	pid_t cpid;

	path = _strdup(original_path); /*create a copy of the original path*/
	command = searchfile(argv, path);
	if (command)
		cpid = fork(); /*start a child process*/
	else
	{
		/**
		 * Handle Error massage
		 */
		write(2, argv[0], _strlen(argv[0]));
		write(2, "\n", 1);
		return (-1);
	}
	if (cpid == -1)
		perror("CPID Error:");
	if (cpid == 0)
	{
		argv[0] = command; /*assign the command read by getline*/
		if (execve(argv[0], argv, environ) == -1)
		{
			perror("EXECVE Error");
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
	free(path);
	free(command);
	return (0);
}
