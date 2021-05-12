#include "monty.h"

/**
* _realloc - re size array
* @ptr: string
* @old_size: int
* @new_size: uns int
* ---------------------------------
* Return: void pointer
*/
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	unsigned int i, cal;
	char *p;
	char *new_ptr;

	if (ptr == NULL)
	{
		p = malloc(new_size);
		if (p == NULL)
			return (NULL);
		for (i = 0; i < new_size; i++)
			p[i] = 0;
		return (p);
	}
	else if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	else if (new_size == old_size)
		return (ptr);
	if (new_size > old_size)
		cal = old_size;
	else
		cal = new_size;
	p = malloc(new_size);
	if (p == NULL)
		return (NULL);
	new_ptr = ptr;
	for (i = 0; i < cal; i++)
		p[i] = new_ptr[i];
	free(ptr);
	return (p);
}

int trash_chrs_amount(char **buff)
{
    int i, j, calc_extra_room = 0;

    if (!buff)
        return (0);

	/* String per string */
	for (i = 0; buff[i]; i++)
	{
		/* It's string char by char */
		for (j = 0; buff[i][j] != '\0'; j++)
		{
			if (buff[i][j] == '\n')
				calc_extra_room++;
		}
	}

    return (calc_extra_room);
}

char **buff_cpy(char **buff)
{
	char **aux = NULL;
	int i;

	aux = malloc((p_strlen(buff) + 1) * sizeof(char *));
	if (!aux)
		return;

	for (i = 0; buff[i]; i++)
		aux[i] = _strcpy(buff[i]);	
	aux[i] = NULL;

	return (aux);
}
