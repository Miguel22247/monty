#include "monty.h"

/* Global Var to store the number */
stack_t *stack_h = NULL;

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
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	monty_file = fopen(argv[1], "r");
	if (!monty_file)
	{
		fprintf(stderr, "Unable to open the file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	/* Add all the file lines to the list */
	while (fgets(monty_line, sizeof(monty_line), monty_file))
		add_nodeline_end(&head, monty_line);
	mega_filter(head);

	free_listline(head);
	free_stack(stack_h);
	exit(EXIT_SUCCESS);
}
