#include <stdio.h>
#include <stdlib.h>

int loop_c(int n);
int loop_s(int n);

int main(int argc, char **argv) {
    int r;
    int n = atoi(argv[1]);

    r = loop_c(n);
    printf("loop_c(%d) = %d\n", n, r);

    r = loop_s(n);
    printf("loop_s(%d) = %d\n", n, r);

    return 0;
}
