#include "monty.h"
/**
 * free_stack - function to free the stack
 * @stack: linked list to be freed
 *
 * Return: void.
 */
void free_stack(stack_t *stack)
{
	stack_t *aux;

	while (stack)
	{
		aux = stack;
		stack = stack->next;
		free(aux);
	}
	free(stack);
}