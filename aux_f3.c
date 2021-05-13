#include "monty.h"

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
