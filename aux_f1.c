#include "monty.h"

/**
 * _strlen - counts the length of a string
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

/**
 * p_strlen - counts the length of a strings array
 * @buff: the strings buff
 * ----------------------------------
 * Return: the length of the buffer
*/
int p_strlen(char **buff)
{
	int i;

	for (i = 0; buff[i]; i++)
		;
	
	return (i);
}

/**
* _strcpy - copies a string
* @src: the source string
*
* Return: A pointer to the copy of str
*/
char *_strcpy(char *src)
{
	int i;
	int src_len = strlen(src) + 1;
	char *dest;

	dest = malloc(src_len * sizeof(char));
	if (!dest)
		return (NULL);

	for (i = 0; i < (src_len - 1); i++)
		dest[i] = src[i];
	dest[i] = '\0';

	return (dest);
}

/**
 * cmds_cleaner - cleanner of trash strings
 * @buff: the strings buffer to clean
 * ----------------------------------------
*/
char **cmds_cleaner(char **buff)
{
	int i, j = 0, trash_str = 0;
	char **new_buff = NULL;

	if (!buff)
		return (NULL);

	new_buff = malloc((p_strlen(buff) + 1) * sizeof(char *));
	if (!new_buff)
		return (NULL);

	/* Move string per string */
	for (i = 0; buff[i]; i++)
	{
		trash_str = strcmp(buff[i], "") + strcmp(buff[i], "\n");
		trash_str += strcmp(buff[i], "\t") + strcmp(buff[i], "\0");
		/* Only add if the str is not a trash one */
		if (trash_str != 0 && buff[i][0] != 0 && buff[i][0] != 10)
			new_buff[j++] = _strcpy(buff[i]);
		free(buff[i]);
	}
	free(buff);
	new_buff[j] = NULL;
	strs_cleaner(&new_buff);

	return (new_buff);
}

/**
 * strs_cleaner - clear all strs
 * @buff: the buffer to clean 
 * 
*/
void strs_cleaner(char ***buff)
{
	int i, j, k = 0, l, has_new_line = 0;
	int calc_extra_room = trash_chrs_amount(*buff);
	char ***new_segment = NULL, **buff_cpy = NULL;

	/* Nothing to clean */
	if (calc_extra_room == 0)
		return;
	new_segment = malloc((calc_extra_room + 1) * sizeof(char **));
	if (!new_segment)
		return;

	/* String per string */
	for (i = 0; buff[0][i]; i++)
	{
		/* It's string char by char */
		for (j = 0; buff[0][i][j] != '\0'; j++)
		{
			/* Trash found */
			if (buff[0][i][j] == '\n')
				new_segment[k++] = _split(buff[0][i], "\n");
		}
	}
	new_segment[k] = NULL;

	buff_cpy = buff_cpy(&buff);
	free(buff);
	buff = malloc((p_strlen(buff_cpy) + calc_extra_room + 1) * sizeof(char *));
	if (!buff)
		return;
	
	for (i = 0; buff[0][i]; i++)
	{
		for (j = 0; buff[0][i][j] != '\0'; j++)
		{
			if (buff[0][i][j] == '\n')
				has_new_line = 1;
		}

		if (has_new_line == 0)
			buff[0][i] = buff_cpy[i];
		else
		{
			/* Each group of string */
			for (; new_segment[k]; k++)
			{
				/* Each string in that group */
				for (l = 0; new_segment[k][l]; l++)
					buff[0][i] = _strcpy(new_segment[k][l]);
			}
			has_new_line = 0;
		}
	}
}
