#ifndef AUX_FUNCS_H
#define AUX_FUNCS_H

/* aux_f1.c */
size_t line_list_len(const line_list *h);
line_list *add_nodeline_end(line_list **head, const int n);
void free_listline(line_list *head);
line_list *get_nodeline_at_index(line_list *head, unsigned int index);

/* EMPTY SLOT */



#endif /* AUX_FUNCS_H */