#include "monty.h"

char number = '0';
/**
* main - Entry point
* @argc: argument counter
* @argv: argument string array
* Return: 0
*/
int main(int argc, char **argv)
{
	FILE *monty_file;
	line_list_t *head = NULL;
	char monty_line[100];

	if (argc == 1 || argc > 2)
		return (1);

	monty_file = fopen(argv[1], "r");
	if (!monty_file)
	{
		perror("Unable to open the file");
		exit (EXIT_FAILURE);
	}
	/* Add all the file lines to the list */
	while (fgets(monty_line, sizeof(monty_line), monty_file))
		add_nodeline_end(&head, monty_line);
	
	mega_filter(head);



	exit(EXIT_SUCCESS);
}
