#include "monty.h"
/**
* fpall - prints the values on the stack
* @stack: stack
* @line_number: number of lines
* Return: void
*/
void fpall(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *head_node = get_stack_at_index(*stack, 0);
	stack_t *last_node = get_stack_at_index(*stack, stack_len(*stack) - 1);
	stack_t *last_prev = last_node->prev;

	last_node->next = head_node->next;
	last_node->prev = NULL;

	last_prev->next = head_node;
	head_node->prev = last_prev;
	head_node->next = NULL;
	*stack = last_node; /* In reality last node is the head */
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

	return;
}

/**
* fpint - prints the value at the top of the stack
* @stack: stack
* @line_number: number of lines
* Return: void
*/
void fpint(__attribute__((unused))stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	printf("command pint executed\n");
}
/**
 * pop_listint - Delete the head
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

	if((*stack)->next != NULL)
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
void fswap(__attribute__((unused))stack_t **stack, __attribute__((unused))unsigned int line_number)
{

}
