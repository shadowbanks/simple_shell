#include "main.h"

/**
 * _unsetenv - Remove an environment varaible if exist
 * @my_env: the environmental variable
 * @name: name of environment variable to remove
 * Return: 0 on success -1 on failure
 */

int _unsetenv(char **my_env, const char *name)
{
        int k = 0, l, check = 0;

        /*search for "name", replace it's value if overwrite != 0*/
        while (my_env[k])
        {
                if (_strncmp(my_env[k], name, _strlen(name)) == 0)
                {
                        if (my_env[k][_strlen(name)] == '=')
                        {
                                check = 1;
                                free(my_env[k]);
                                break;
                        }
                }
                k++;
        }

        if (check == 1)
        {
                l = k + 1;

                while (my_env[l])
                {
                        my_env[k] = my_env[l];
                        k++, l++;
                }
                my_env[k] = NULL;

                return (0);
        }
        return (-1);
}
