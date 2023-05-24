#include "main.h"

/**
 * check_env - check if an environment exist
 * or a new is needed
 * @my_env: environment variables
 * @new_env: new environment variable
 * @overwrite: 0 (value shouldn't change) else (change value)
 * @name: environment name
 *
 * Return: 0 (success), 1 (failure)
 */
int check_env(char **my_env, char *new_env, int overwrite, const char *name)
{
        int k = 0;
        char *temp = NULL;

        /*search for "name", replace it's value if overwrite != 0*/
        while (my_env[k])
        {
                if (_strncmp(my_env[k], name, _strlen(name)) == 0)
                {
                        if (my_env[k][_strlen(name)] == '=')
                        {
                                if (overwrite != 0)
                                {
                                        temp = my_env[k];
                                        my_env[k] = new_env;
                                        free(temp);
                                }
                                else
                                        return (1);
                                break;
                        }
                }
                k++;
        }
        if (my_env[k] == NULL)
        {
                my_env[k++] = new_env;
                my_env[k] = NULL;
        }
        return (0);
}
