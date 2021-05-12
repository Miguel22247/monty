#include "monty.h"

/**
 * mega_filter - process the file commands
 * @h: the linked list head
 * ------------------------------
*/
void mega_filter(line_list_t *h, stack_t *stack)
{
	line_list_t *cursor = h;
	char *token = NULL;

	while (cursor)
	{
		token = strtok(cursor->str, " \n\t");
		/* Navigate throgh commands */
		while (token)
		{
			command_geiger(token, stack);

			printf("part: %s\n", token);
			token = strtok(NULL, " \n\t");
		}

		cursor = cursor->next;
	}
}

void command_geiger(char *str, stack_t *stack)
{
	int i;

	instruction_t commands[] = {
		{"pall", fpall},
		{"push", fpush},
		{"pint", fpint},
		{"pop", fpop},
		{"swap", fswap},
		{"add", fadd},
		{"nop", fnop},
		{NULL, NULL}
	};

	for (i = 0; commands[i].opcode; i++)
	{
		if (strcmp(str, commands[i].opcode) == 0)
		{
			number = strtok(NULL, " \n\t");
			if (number == 0 && strcmp(number, "0") != 0)
			{
				perror("Error: Syntax not correct\n");
				exit(EXIT_FAILURE);
			}
			commands[i].f(&stack, atoi(number));
			return;
		}
	}
}
