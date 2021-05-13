#include "monty.h"

/**
 * line_list_len - calculate the length of a list
 * @h: head node of the list
 * ----------------------------------
 * Return: ammount of elements in the list
*/
size_t line_list_len(const line_list_t *h)
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
 * add_nodeline_end - add a new node at the end of a list
 * @head: the head node
 * @str: the str data of the node
 * -------------------------------------------
 * Return: the new node
*/
line_list_t *add_nodeline_end(line_list_t **head, char *str)
{
	line_list_t *new = NULL;
	line_list_t *current = NULL;
	int line_position = 1;

	new = malloc(sizeof(line_list_t));
	if (!new)
		return (NULL);


	new->str = malloc((strlen(str) + 1) * sizeof(char));
	if (!new->str)
		return (NULL);
	strcpy(new->str, str);
	new->line_n = line_position;
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
			new->line_n = line_position + 1;
			new->prev = current;
			current->next = new;
			break;
		}
		line_position++;
		current = current->next;
	}

	return (new);
}

/**
 * free_listline - frees a list
 * @head: the head node to start cleanning
 * -------------------------------------------
*/
void free_listline(line_list_t *head)
{
	line_list_t *aux = head;

	while (head)
	{
		head = head->next;
		free(aux->str);
		free(aux);
		aux = head;
	}
}

/**
 * get_nodeline_at_index - returns a node at an index
 * @head: the head node
 * @index: the index to look at the node
 * --------------------------------------------
 * Return: the target node or NULL if nothing has been founded
*/
line_list_t *get_nodeline_at_index(line_list_t *head, unsigned int index)
{
	line_list_t *target = NULL;
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

/**
 * print_list_line - print a list
 * @h: head node of the list
 * ----------------------------------
 *Return: ammount of elements in the list
*/
size_t print_list_line(const line_list_t *h)
{
	size_t i = 0;

	printf("==== Printing list of lines ====\n");

	while (h != NULL)
	{
		i++;
		printf("line: %s", h->str);
		printf("number: %d\n", h->line_n);
		h = h->next;
	}

	printf("===========================\n");

	return (i);
}
