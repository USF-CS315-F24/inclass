#include <stdio.h>
#include <stdlib.h>

int add3_c(int a, int b, int c);
int add3_s(int a, int b, int c);

int main(int argc, char *argv[]) {
    int r;
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
    int c = atoi(argv[3]);

    r = add3_c(a, b, c);
    printf("add3_c(%d, %d, %d) = %d\n", a, b, c, r);

    r = add3_s(a, b, c);
    printf("add3_s(%d, %d, %d) = %d\n", a, b, c, r);

    return 0;
}
