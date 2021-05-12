#ifndef AUX_FUNCS_H
#define AUX_FUNCS_H

/* aux_f1.c */
int _strlen(char *str);
int p_strlen(char **buff);
char *_strcpy(char *src);
char **cmds_cleaner(char **buff);
void strs_cleaner(char ***buff);

/* aux_f2.c */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
int trash_chrs_amount(char **buff);
char **buff_cpy(char **buff);

/* _splits1.c */
char **_split(char *, char *c);
int calc_lines(char *, char *c);
void free_split(char **splitted);
int check_split_line(char *, int, char *, int *, int *);
int remove_commas(char **uwu);

/* _splits2.c */
void comms_pross(char *, int *, int *, int *, int *);
/* EMPTY SLOT */
/* EMPTY SLOT */
/* EMPTY SLOT */
/* EMPTY SLOT */



#endif /* AUX_FUNCS_H */