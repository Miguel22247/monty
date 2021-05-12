#include "monty.h"

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
 * cmds_cleaner - cleanner of trash strings
 * @buff: the strings buffer to clean
 * ----------------------------------------
*/
void cmds_cleaner(char **buff)
{
	int i, j = 0, trash_str = 0;
	char **new_buff = NULL;

	if (!buff)
		return;

	printf("1====================\n");

	new_buff = malloc(p_strlen(buff));
	if (!new_buff)
		return;

	printf("2====================\n");


	/* Move string per string */
	for (i = 0; buff[i]; i++)
	{
		trash_str = strcmp(buff[i], "") + strcmp(buff[i], "\n");
		trash_str += strcmp(buff[i], "\t") + strcmp(buff[i], "\0");
		/* Only add if the str is not a trash one */
		printf("3====================\n");
		if (trash_str != 0)
		{
			printf("str actual: %s\n", buff[i]);
			new_buff[j++] = strcpy(new_buff[j], buff[i]);
			printf("str copied: %s\n", new_buff[j]);
		}
		free(buff[i]);
	}
	free(buff);
	buff = new_buff;
}
