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
 * pint_err - when a pint is wrong typed
 * @node: the node where push failed
 * @f: file to close
 * -----------------------------------------
*/
void pint_err(line_list_t *node, FILE *f)
{
	fprintf(stderr, "L%d: can't pint, stack empty\n", node->line_n);

	free_listline(reach_head(node));
	free_stack(stack_h);
	fclose(f);
	exit(EXIT_FAILURE);
}

/**
 * pop_err - when a push is wrong typed
 * @node: the node where push failed
 * @f: file to close
 * -----------------------------------------
*/
void pop_err(line_list_t *node, FILE *f)
{
	fprintf(stderr, "L%d: can't pop an empty stack\n", node->line_n);
	
	free_listline(reach_head(node));
	free_stack(stack_h);
	fclose(f);
	exit(EXIT_FAILURE);
}
