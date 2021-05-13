#ifndef MONTY_H
#define MONTY_H

/* System Libraries*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <stddef.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

/* Structs */
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
/**
 * struct line_list_s - lines amount
 * @str: the line
 * @prev: points to the previous element of the list
 * @next: points to the next element of the list
 * @line_n: new line?
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct line_list_s
{
	char *str;
	int line_n;
	struct line_list_s *prev;
	struct line_list_s *next;
} line_list_t;
/**
 * struct error_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct error_s
{
	char *opcode;
	void (*f)(line_list_t *node, FILE *f);
} error_t;



/* Our Libraries */
#include "aux_funcs.h"


/* Global Var to store (Stack Head) */
extern stack_t *stack_h;

#endif /* MONTY_H */
