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

/**
 * free_stack - frees a list
 * @head: the head node to start cleanning
 * -------------------------------------------
*/
void free_stack(stack_t *head)
{
	stack_t *aux = head;

	while (head)
	{
		head = head->next;
		free(aux);
		aux = head;
	}
}

/**
* reach_head - go to the head of every node
* @node: node to be reached
* Return: head node
*/
line_list_t *reach_head(line_list_t *node)
{
	line_list_t *head = node;

	while (!head->prev)
		head = head->prev;

	return (head);
}
