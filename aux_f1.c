#include "monty.h"

/**
 * line_list_len - calculate the length of a list
 * @h: head node of the list
 * ----------------------------------
 * Return: ammount of elements in the list
*/
size_t line_list_len(const line_list *h)
{
	size_t i = 0;

	while (h != NULL)
	{
		i++;
		h = h->next;
	}

	return (i);
}

/**
 * add_dnodeint_end - add a new node at the end of a list
 * @head: the head node
 * @n: the int data of the node
 * -------------------------------------------
 * Return: the new node
*/
line_list *add_nodeline_end(line_list **head, const int n)
{
	line_list *new = NULL;
	line_list *current = NULL;

	new = malloc(sizeof(line_list));
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

/**
 * free_dlistint - frees a list
 * @head: the head node to start cleanning
 * -------------------------------------------
*/
void free_listline(line_list *head)
{
	line_list *aux = head;

	while (head)
	{
		head = head->next;
		free(aux);
		aux = head;
	}
}

/**
 * get_dnodeint_at_index - returns a node at an index
 * @head: the head node
 * @index: the index to look at the node
 * --------------------------------------------
 * Return: the target node or NULL if nothing has been founded
*/
line_list *get_nodeline_at_index(line_list *head, unsigned int index)
{
	line_list *target = NULL;
	unsigned int target_i = 0;

	if (!head)
		return (NULL);

	target = head;
	while (target && target_i != index)
	{
		target_i++;
		target = target->next;
	}

	/* Not index was found */
	if (!target)
		return (NULL);

	return (target);
}
