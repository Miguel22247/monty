#include "monty.h"

/**
 * push_err - when a push is wrong typed
 * @node: the node where push failed
 * @f: file to close
 * -----------------------------------------
*/
void push_err(line_list_t *node, FILE *f)
{
	fprintf(stderr, "L%d: usage: push integer\n", node->line_n);

	free_listline(reach_head(node));
	free_stack(stack_h);
	fclose(f);
	exit(EXIT_FAILURE);
}

/**
 * push_err - when a push is wrong typed
 * @node: the node where push failed
 * @f: file to close
 * -----------------------------------------
*/
void pop_err(line_list_t *node, FILE *f)
{
	node = node;
	f = f;
}
