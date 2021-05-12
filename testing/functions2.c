#include "test.h"
/**
 * fswap - swaps first two elements of stack
 * @stack: list where values will be stored
 * @line_number: number of line being read. In case of error
 * Return: void
 */
void fswap(stack_t **stack, unsigned int line_number)
{
	unsigned int swap = 0;
	size_t len = 0;

	len = stack_tlen(stack);

	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free_list(*stack);
		exit(EXIT_FAILURE);
	}
	swap = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = swap;
}
/**
 * fadd - adds first two elements of stack. Stores result in elm2, deletes elm1
 * @stack: list where values will be stored
 * @line_number: number of line being read. In case of error
 * Return: void
 */
void fadd(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	unsigned int add = 0;
	size_t len = 0;

	len = stack_tlen(stack);

	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free_list(*stack);
		exit(EXIT_FAILURE);
	}
	add = (*stack)->n + (*stack)->next->n;
	temp = *stack;
	(*stack) = (*stack)->next;
	(*stack)->n = add;
	(*stack)->prev = NULL;
	free(temp);
}

/**
 * fnop - does not do anything
 * @stack: list where values will be stored
 * @line_number: number of line being read. In case of error
 * Return: void
 */
void fnop(stack_t **stack, unsigned int line_number)
{
	(void) *stack;
	(void) line_number;
}


