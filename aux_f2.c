#include "monty.h"

/**
 * mega_filter - process the file commands
 * @h: the linked list head
 * @f: file to close
 * ------------------------------
*/
void mega_filter(line_list_t *h, FILE *f)
{
	line_list_t *cursor = h;
	int vuelta;
	char *token = NULL;

	while (cursor)
	{
		vuelta = 0;
		token = strtok(cursor->str, " \n\t");

		/* Navigate throgh line */
		while (token)
		{
			vuelta++;
			command_geiger(&token, cursor, vuelta, f);
			token = strtok(NULL, " \n\t");
		}

		cursor = cursor->next;
	}
}

/**
* command_geiger - list all the functions
* @str: string
* @node: node
* @vuelta: vuelta
* @f: file to close
*/
void command_geiger(char **str, line_list_t *node, int vuelta, FILE *f)
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
		if (strcmp(*str, commands[i].opcode) == 0)
		{
			if (strcmp(*str, "pall") == 0 || strcmp(*str, "pint") == 0
			|| strcmp(*str, "pop") == 0)
			{
				single_cmds_err_chk(*str, node, f);
				commands[i].f(&stack_h, 0);
				return;
			}
			number = strtok(NULL, " \n\t");
			cmds_error_check(*str, number, node, f);
			*str = number;
			commands[i].f(&stack_h, atoi(number));
			return;
		}
	if (vuelta == 1)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", node->line_n, *str);
		free_stack(stack_h);
		free_listline(reach_head(node));
		fclose(f);
		exit(EXIT_FAILURE);
	}
}

void single_cmds_err_chk(char *str, line_list_t *node, FILE *f)
{
	int i;
	error_t commands[] = {
		{"pop", pop_err},
		{"pint", pop_err},
		{NULL, NULL}
	};

	for (i = 0; commands[i].opcode; i++)
	{
		if (strcmp(str, commands[i].opcode) == 0)
		{
			if (!stack_h)
				commands[i].f(node, f);
		}
	}
}

/**
 * cmds_error_check - Checks if the command is well typed
 * @str: the command token
 * @num: the next token.. normally a number
 * @node: the node where it command is executed
 * @f: file to close
 * ------------------------------------------------------
*/
void cmds_error_check(char *str, char *num, line_list_t *node, FILE *f)
{
	int i;
	error_t commands[] = {
		{"pall", NULL},
		{"push", push_err},
		{"pint", pint_err},
		{"pop", pop_err},
		{"swap", NULL},
		{"add", NULL},
		{"nop", NULL},
		{NULL, NULL}
	};

	if (!num || (check_impostor_str(num) == 0))
	{
		/* Navigate through errors and find it */
		for (i = 0; commands[i].opcode; i++)
		{
			if (strcmp(str, commands[i].opcode) == 0)
				commands[i].f(node, f);
		}
		fprintf(stderr, "L%d: unknown instruction %s\n", node->line_n,
		commands[i].opcode);
		free_stack(stack_h);
		free_listline(reach_head(node));
		fclose(f);
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
