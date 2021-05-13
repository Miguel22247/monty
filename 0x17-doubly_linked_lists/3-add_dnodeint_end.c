#include "lists.h"

/**
 * add_dnodeint_end - add a new node at the end of a list
 * @head: the head node
 * @n: the int data of the node
 * -------------------------------------------
 * Return: the new node
*/
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new = NULL;
	dlistint_t *current = NULL;

	new = malloc(sizeof(dlistint_t));
	if (!new)
		return (NULL);

	new->n = n;
	new->next = NULL;
	new->prev = NULL;

	if (!head || !(*head))
	{
		*head = new;
		return (new);
	}

	current = *head;
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

	return (new);
}
