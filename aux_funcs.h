#ifndef AUX_FUNCS_H
#define AUX_FUNCS_H

/* aux_f1.c */
size_t line_list_len(const line_list_t *h);
line_list_t *add_nodeline_end(line_list_t **head, char *str);
void free_listline(line_list_t *head);
line_list_t *get_nodeline_at_index(line_list_t *head, unsigned int index);
size_t print_dlistint(const line_list_t *h);

/* aux_f2.c */
void mega_filter(line_list_t *h);

#endif /* AUX_FUNCS_H */