#include "main.h"

/**
 * _realloc - reallocates a momeory block using malloc and free
 * @ptr: pointer to old block of memory
 * @old_size: size of the old block of memory
 * @new_size: size of the new block of memory
 *
 * Return: pointer to memory block or NULL
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
        void *new = NULL;

        if (ptr != NULL)
        {
                if (new_size == old_size)
                        return (ptr);
                if (new_size == 0)
                {
                        free(ptr);
                        return (NULL);
                }
                else if (new_size > old_size)
                {
                        new = malloc(new_size);
                        if (new != NULL)
                        {
                                memcpy(new, ptr, old_size);
                                free(ptr);
                                return (new);
                        }
                }
        }
        ptr = malloc(new_size);
        if (ptr == NULL)
                return (NULL);
        return (ptr);
}

