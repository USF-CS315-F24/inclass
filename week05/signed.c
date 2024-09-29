#include <stdio.h>

int main(int argc, char *argv[]) {
    int x = -1;

    printf("x = %d\n", x);
    printf("x = %X\n", x);

    x = -1999;
    
    printf("x = %d\n", x);
    printf("x = %X\n", x);

    x = ~(x - 1);
    x = (~x) + 1;

    printf("x = %d\n", x);
    printf("x = %X\n", x);

    return 0;
}
