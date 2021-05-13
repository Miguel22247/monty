#ifndef AUX_FUNCS_H
#define AUX_FUNCS_H

/* aux_f1.c */
size_t line_list_len(const line_list_t *h);
line_list_t *add_nodeline_end(line_list_t **head, char *str);
void free_listline(line_list_t *head);
line_list_t *get_nodeline_at_index(line_list_t *head, unsigned int index);
size_t print_list_line(const line_list_t *h);

/* aux_f2.c */
void mega_filter(line_list_t *h);
void command_geiger(char **str, line_list_t *node, int vuelta);
size_t print_stack(const stack_t *h);
void cmds_error_check(char *str, char *num, line_list_t *node);
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
stack_t *get_stack_at_index(stack_t *head, unsigned int index);
size_t stack_len(const stack_t *h);
/* EMPTY SLOT */

/* err_funcs1.c */
void push_err(line_list_t *node);
/* EMPTY SLOT */
/* EMPTY SLOT */
/* EMPTY SLOT */
/* EMPTY SLOT */

#endif /* AUX_FUNCS_H */
