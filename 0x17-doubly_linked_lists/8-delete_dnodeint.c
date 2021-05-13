#include "lists.h"
#include "5-get_dnodeint.c"
#include "1-dlistint_len.c"

/**
* delete_dnodeint_at_index - delete a node in an index
* @head: the head node
* @index: the index target
* ------------------------------------------
* Return: 1 if worked, -1 if not
*/
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *target = NULL, *t_prev = NULL, *t_next = NULL;

	if (!head || !(*head))
		return (-1);

	if ((index > dlistint_len(*head) - 1))
		return (-1);

	if (index > 0)
		t_prev = get_dnodeint_at_index(*head, index - 1);
	target = get_dnodeint_at_index(*head, index);
	if (index != dlistint_len(*head) - 1)
	{
		t_next = get_dnodeint_at_index(*head, index + 1);
		t_next->prev = NULL;
	}

	if (index > 0)
	{
		t_prev->next = t_next;
		if (t_next)
			t_next->prev = t_prev;
	}
	else
		*head = t_next;

	free(target);

	return (1);
}
