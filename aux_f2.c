#include "monty.h"

/**
 * mega_filter - process the file commands
 * @h: the linked list head
 * ------------------------------
*/
void mega_filter(line_list_t *h)
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
			command_geiger(&token, cursor);
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
* Return: void
*/
void command_geiger(char **str, line_list_t *node)
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
			if (atoi(number) == 0 && strcmp(number, "0") != 0)
			{
				if (strcmp(commands[i].opcode, "push") == 0)
					push_err(node);
				fprintf(stderr, "L%d: unknown instruction %s\n", node->line_n,
				commands[i].opcode);
				exit(EXIT_FAILURE);
			}
			/* advance one token */
			*str = number;
			commands[i].f(&stack_h, atoi(number));
			return;
		}
	}
}
/**
* print_stack - print the stack
* @h: head
* Return: stack
*/
size_t print_stack(const stack_t *h)
{
	size_t i = 0;

	while (h != NULL)
	{
		i++;
		printf("%d\n", h->n);
		h = h->next;
	}

	return (i);
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
