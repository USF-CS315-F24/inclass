#include <stdio.h>

int add4f_c(int a, int b, int c, int d);
int add4f_s(int a, int b, int c, int d);
//int add4f_callee_s(int a, int b, int c, int d);

int main(int argc, char *argv[]) {
    int x;

    x = add4f_c(1, 2, 3, 4);
    printf("add4f_c(1, 2, 3, 4) = %d\n", x);

    x = add4f_s(1, 2, 3, 4);
    printf("add4f_s(1, 2, 3, 4) = %d\n", x);

    //x = add4f_callee_s(1, 2, 3, 4);
    //printf("add4f_callee_s(1, 2, 3, 4) = %d\n", x);

    return 0;
}
