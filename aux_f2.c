#include "monty.h"

/**
 * mega_filter - process the file commands
 * @h: the linked list head
 * ------------------------------
*/
void mega_filter(line_list_t *h)
{
    line_list_t *cursor = h;
    char *token = NULL;

    while (cursor)
    {
        token = strtok(cursor->str, " \n\t");
        /* Navigate throgh commands */
        while (token)
        {


            printf("part: %s\n", token);
            token = strtok(NULL, " \n\t");
        }

        cursor = cursor->next;
    }
}


void command_geiger(char *str)
{
    
}
