#include "monty.h"

/**
 * push_err - when a push is wrong typed
 * @node: the node where push failed
 * -----------------------------------------
*/
void push_err(line_list_t *node)
{
	fprintf(stderr, "L<%d>: usage: push integer\n", node->line_n);
	exit(EXIT_FAILURE);
}
