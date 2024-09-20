#include <stddef.h>
#include "linkedlist.h"

int countll_c(struct node_st *np) {
    int len = 0;

    // Traverse the linked list until we get to the end
    while (np != NULL) {
        len += 1;
        np = np->next_p;
    }

    return len;
}
