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

	while (head->prev)
		head = head->prev;

	return (head);
}

/**
* check_impostor_str - check if the string has an impostor
* @str: string to be analized if contains an impostor
* Return: an impostor(0) or not(1)
*/
int check_impostor_str(char *str)
{
	int i = 0;

	if (str[0] == '\0')
		return (0);

	if (str[0] == '-' && (str[1] >= 48 && str[1] <= 57))
		i = 1;

	for (; str[i] != '\0'; i++)
	{
		if (str[i] < 48 || str[i] > 57)
			return (0);
	}

	return (1);
}
