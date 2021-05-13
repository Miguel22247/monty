#include "monty.h"

/**
 * mega_filter - process the file commands
 * @h: the linked list head
 * ------------------------------
*/
void mega_filter(line_list_t *h)
{
	line_list_t *cursor = h;
	int vuelta;
	char *token = NULL, *original_str_saver = NULL;

	while (cursor)
	{
		vuelta = 0;
		original_str_saver = malloc((strlen(cursor->str) + 1) * sizeof(char));
		if (!original_str_saver)
			return;
		strcpy(original_str_saver, cursor->str);

		token = strtok(original_str_saver, " \n\t");

		/* Navigate throgh line */
		while (token)
		{
			vuelta++;
			command_geiger(&token, cursor, vuelta);
			token = strtok(NULL, " \n\t");
		}

		free(original_str_saver);
		cursor = cursor->next;
	}
}
/**
* command_geiger - list all the functions
* @str: string
* @node: node
* @vuelta: vuelta
* Return: void
*/
void command_geiger(char **str, line_list_t *node, int vuelta)
{
	int i;
	char *number = NULL;

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
			if (strcmp(*str, "pall") == 0)
			{
				commands[i].f(&stack_h, 0);
				return;
			}

			/* Ask for number */
			number = strtok(NULL, " \n\t");
			cmds_error_check(*str, number, node);

			/* advance one token */
			*str = number;
			commands[i].f(&stack_h, atoi(number));
			return;
		}
	}
	if (vuelta == 1)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", node->line_n, *str);
		exit(EXIT_FAILURE);
	}
}

/**
 * cmds_error_check - Checks if the command is well typed
 * @str: the command token
 * @num: the next token.. normally a number
 * @node: the node where it command is executed
 * ------------------------------------------------------
*/
void cmds_error_check(char *str, char *num, line_list_t *node)
{
	int i;
	error_t commands[] = {
		{"pall", NULL},
		{"push", push_err},
		{"pint", NULL},
		{"pop", NULL},
		{"swap", NULL},
		{"add", NULL},
		{"nop", NULL},
		{NULL, NULL}
	};

	if (!num || (atoi(num) == 0 && strcmp(num, "0") != 0))
	{
		/* Navigate through errors and find it */
		for (i = 0; commands[i].opcode; i++)
		{
			if (strcmp(str, commands[i].opcode) == 0)
				commands[i].f(node);
		}
		fprintf(stderr, "L%d: unknown instruction %s\n", node->line_n,
		commands[i].opcode);
		exit(EXIT_FAILURE);
	}
}

/**
 * get_stack_at_index - returns a node at an index
 * @head: the head node
 * @index: the index to look at the node
 * --------------------------------------------
 * Return: the target node or NULL if nothing has been founded
*/
stack_t *get_stack_at_index(stack_t *head, unsigned int index)
{
	stack_t *target = NULL;
	unsigned int target_i = 0;

	if (!head)
		return (NULL);

	target = head;
	while (target && target_i != index)
	{
		target_i++;
		target = target->next;
	}

	/* Not index was found */
	if (!target)
		return (NULL);

	return (target);
}

/**
 * stack_len - calculate the length of a list
 * @h: head node of the list
 * ----------------------------------
 * Return: ammount of elements in the list
*/
size_t stack_len(const stack_t *h)
{
	size_t i = 0;

	while (h != NULL)
	{
		i++;
		h = h->next;
	}

	return (i);
}
