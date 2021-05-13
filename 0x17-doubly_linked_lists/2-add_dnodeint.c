#include "lists.h"

/**
 * add_dnodeint - adds a new node at the beggining
 * @head: the head node
 * @n: the node data int
 * -----------------------------------
 * Return: the new node
*/
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new = NULL;

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

	(*head)->prev = new;
	new->next = *head;
	new->prev = NULL;
	*head = new;

	return (new);
}
