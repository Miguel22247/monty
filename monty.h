#ifndef MONTY_H
#define MONTY_H

/* System Libraries*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

/* Our Libraries */
#include "aux_funcs.h"

/* variable */
extern char number;

/* Structures */
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
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct line_list
{
	char *opcode;
	struct line_list *next;
	struct line_list *prev;
} line_list;

/* _splits1.c */
char **_split(char *, char *c);
int calc_lines(char *, char *c);
void free_split(char **splitted);
int check_split_line(char *, int, char *, int *, int *);
int remove_commas(char **uwu);

/* _splits2.c */
void comms_pross(char *, int *, int *, int *, int *);

/* aux_f2.c */
int trash_chrs_amount(char **buff);
char **cmds_cleaner(char **buff);
/* functions */
void fpush(stack_t **stack, unsigned int line_number);
void fpall(stack_t **stack, unsigned int line_number);
void fpint(stack_t **stack, unsigned int line_number);
void fpop(stack_t **stack, unsigned int line_number);
void fswap(stack_t **stack, unsigned int line_number);
void fadd(stack_t **stack, unsigned int line_number);
void fnop(stack_t **stack, unsigned int line_number);
void free_stack(stack_t *stack);
#endif /* MONTY_H */