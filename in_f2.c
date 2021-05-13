#include "monty.h"
/**
* fadd - adds the top two elements of the stack
* @stack: stack
* @line_number: number of lines being read
* Return: nothing
*/
void fadd(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	printf("command sadd %d executed\n", stack[0]->n);
}

/**
* fnop - doesn't do anything
* @stack: stack
* @line_number: number of lines being read
* Return: nothing
* Description: (void) es un puntero vacio
*/
void fnop(stack_t **stack, unsigned int line_number)
{
	stack = stack;
	line_number = line_number;
}
