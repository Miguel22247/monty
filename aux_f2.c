#include "monty.h"

/**
 * mega_filter - process the file commands
 * @h: the linked list head
 * ------------------------------
*/
void mega_filter(line_list_t *h, stack_t *stack)
{
	line_list_t *cursor = h;
	char *token = NULL, *original_str_saver = NULL;

	while (cursor)
	{
		original_str_saver = malloc((strlen(cursor->str) + 1) * sizeof(char));
		if (!original_str_saver)
			return;
		strcpy(original_str_saver, cursor->str);

		token = strtok(original_str_saver, " \n\t");
		/* Navigate throgh line */
		while (token)
		{
			printf("part: %s\n", token);
			command_geiger(&token, stack);
			token = strtok(NULL, " \n\t");
		}

		free(original_str_saver);
		cursor = cursor->next;
	}
}

void command_geiger(char **str, stack_t *stack)
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
		if (strcmp(*str, commands[i].opcode) == 0)
		{
			/* Commands that don't asks for numbers */
			if (strcmp(commands[i].opcode, "pall") == 0)
			{
				commands[i].f(&stack, atoi(number));
				return;
			}

			/* Ask for number */
			number = strtok(NULL, " \n\t");
			printf("number value: %s\n", number);
			if (atoi(number) == 0 && strcmp(number, "0") != 0)
			{
				perror("Error: Syntax not correct\n");
				exit(EXIT_FAILURE);
			}
			/* advance one token */
			*str = number;
			commands[i].f(&stack, atoi(number));
			return;
		}
	}
}
