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
#include "structs.h"

/* Our Libraries */
#include "aux_funcs.h"

/* Global Var to store (Stack Head) */
extern stack_t *stack_h;

#endif /* MONTY_H */
