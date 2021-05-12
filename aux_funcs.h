#ifndef AUX_FUNCS_H
#define AUX_FUNCS_H

/* aux_f1.c */
size_t line_list_len(const line_list_t *h);
line_list_t *add_nodeline_end(line_list_t **head, char *str);
void free_listline(line_list_t *head);
line_list_t *get_nodeline_at_index(line_list_t *head, unsigned int index);
size_t print_dlistint(const line_list_t *h);

/* aux_f2.c */
void mega_filter(line_list_t *h, stack_t *stack);
void command_geiger(char *str, stack_t *stack);
/* EMPTY SLOT */
/* EMPTY SLOT */
/* EMPTY SLOT */

/* in_f1.c */
void fpall(stack_t **stack, unsigned int line_number);
void fpush(stack_t **stack, unsigned int line_number);
void fpint(stack_t **stack, unsigned int line_number);
void fpop(stack_t **stack, unsigned int line_number);
void fswap(stack_t **stack, unsigned int line_number);

/* in_f2.c */
void fadd(stack_t **stack, unsigned int line_number);
void fnop(stack_t **stack, unsigned int line_number);
/* EMPTY SLOT */
/* EMPTY SLOT */
/* EMPTY SLOT */

#endif /* AUX_FUNCS_H */