#include "lists.h"

/**
 * sum_dlistint - the sum of all nodes
 * @head: the head node
 * -------------------------------
 * Return: the sum of all nodes in an integer
*/
int sum_dlistint(dlistint_t *head)
{
	int sum = 0;

	while (head)
	{
		sum += head->n;
		head = head->next;
	}

	return (sum);
}
