#include <stdio.h>
#include <stdlib.h>

#include "linkedlist.h"

int countll_c(struct node_st *np);
int countll_s(struct node_st *np);


int main(int argc, char *argv[]) {
    // Allocate node_st structs on the stack
    struct node_st n0, n1, n2, n3;
    int r;

    // Manually construct a linked list
    n0.value = 11;
    n0.next_p = &n1;

    n1.value = 22;
    n1.next_p = &n2;

    n2.value = 33;
    n2.next_p = &n3;

    n3.value = 44;
    n3.next_p = NULL;

    r = countll_c(&n0);
    printf("countll_c(%p) = %d\n", &n0, r);

    r = countll_s(&n0);
    printf("countll_s(%p) = %d\n", &n0, r);

    return 0;
}
