#include "monty.h"
/**
* fadd - adds the top two elements of the stack
* @stack: stack
* @line_number: number of lines being read
* Return: nothing
*/
void fadd(__attribute__((unused))stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	printf("command add executed\n");
}

/**
* fnop - doesn't do anything
* @stack: stack
* @line_number: number of lines being read
* Return: nothing
* Description: (void) es un puntero vacio
*/
void fnop(__attribute__((unused))stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	/*
	(void) *stack;
	(void) line_number;
	*/
}
