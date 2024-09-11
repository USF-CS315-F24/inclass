#include <stdio.h>

int foo_c(int a);
int foo_s(int a);

int main(int argc, char *argv[]) {
    int x;

    x = foo_c(3);
    printf("foo_c(3) = %d\n", x);

    x = foo_s(3);
    printf("foo_s(3) = %d\n", x);

    return 0;
}
