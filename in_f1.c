#include "monty.h"
/**
* fpall - prints the values on the stack
* @stack: stack
* @line_number: number of lines
* Return: void
*/
void fpall(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *aux = get_stack_at_index(*stack, stack_len(*stack) - 1);

	while (aux)
	{
		printf("%d\n", aux->n);
		aux = aux->prev;
	}
}

/**
* fpush - pushes the elements to the stack
* @stack: stack
* @line_number: number of lines
* Return: void
*/
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
}

/**
* fpint - prints the value at the top of the stack
* @stack: stack
* @line_number: number of lines
* Return: void
*/
void fpint(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *h = *stack;

	while (h->next)
		h = h->next;

	printf("%d\n", h->n);
}
/**
 * fpop - Delete the head
 * @stack: pointer to the head node
 * @line_number: line number
 * Return: Nothing
 */
void fpop(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->next != NULL)
	{
		*stack = (*stack)->next;
		free((*stack)->prev);
		(*stack)->prev = NULL;
	}
	else
	{
		free(*stack);
		*stack = NULL;
	}
}
/**
* fswap - swaps the top two elements of the stack.
* @stack: stack
* @line_number: number of lines
* Return: void
*/
void fswap(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	printf("command swap %d executed\n", stack[0]->n);
}
