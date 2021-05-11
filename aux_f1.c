#include "aux_funcs.h"

/**
* p_strlen - counts the length of a string
* @str: the string
* ---------------------------------
* Return: the length of the string
*/
int _strlen(char *str)
{
	int i;

	for (i = 0; str[i]; i++)
        ;

	return (i);
}
