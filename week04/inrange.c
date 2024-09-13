#include <stdio.h>

int inrange_c(int x, int a, int b);
int inrange_s(int x, int a, int b);

int main(int argc, char *argv[]) {
    int r;

    r = inrange_c(3, 1, 7);
    printf("inrange_c(3, 1, 7) = %d\n", r);
    r = inrange_c(10, 1, 7);
    printf("inrange_c(10, 1, 7) = %d\n", r);

    r = inrange_s(3, 1, 7);
    printf("inrange_s(3, 1, 7) = %d\n", r);
    r = inrange_s(10, 1, 7);
    printf("inrange_s(3, 1, 10) = %d\n", r);

    return 0;
}
