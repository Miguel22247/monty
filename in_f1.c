#include "monty.h"

void fpall(__attribute__((unused))stack_t **stack, __attribute__((unused))unsigned int line_number)
{
    printf("command pall executed\n");
}

void fpush(stack_t **stack, unsigned int line_number)
{
    stack_t *new = NULL;
	stack_t *current = NULL;

	new = malloc(sizeof(stack_t));
	if (!new)
		return;

	new->n = line_number;
	new->next = NULL;
	new->prev = NULL;

	if (!stack || !(*stack))
	{
		*stack = new;
		return;
	}

	current = *stack;
	while (current)
	{
		if (!current->next)
		{
			new->prev = current;
			current->next = new;
			break;
		}
		current = current->next;
	}

	return;
}

void fpint(__attribute__((unused))stack_t **stack, __attribute__((unused))unsigned int line_number)
{
    printf("command pint executed\n");
}

void fpop(__attribute__((unused))stack_t **stack, __attribute__((unused))unsigned int line_number)
{
    printf("command poop executed\n");
}

void fswap(__attribute__((unused))stack_t **stack, __attribute__((unused))unsigned int line_number)
{
    printf("command swap executed\n");
}
