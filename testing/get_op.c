#include "monty.h"

int get_op(stack_t **stack, char *tok_op, unsigned int line_number)
{
instruction_t commands[] = {
		{"pall", fpall},
		{"push", fpush},
		{"pint", fpint},
		{"pop", fpop},
		{"swap", fswap},
		{"add", fadd},
		{"nop", fnop},
};
int i = 0;

	while (commands[i].opcode != NULL)
	{
		if (strcmp(commands[i].opcode, tok_op) == 0)
		{
			commands[i].f(stack, line_number);
			return (0);
		}
		i++;
	}
	fprintf(stderr, "L%i: unknown instruction %s\n", line_number, tok_op);
	free_stack(*stack);
	exit(EXIT_FAILURE);
}