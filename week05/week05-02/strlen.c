#include <stdio.h>

int strlen_c(char *s);
int strlen_s(char *s);

int main(int argc, char *argv[]) {
    int len;

    len = strlen_c(argv[1]);
    printf("strlen_c(%s) = %d\n", argv[1], len);

    len = strlen_s(argv[1]);
    printf("strlen_s(%s) = %d\n", argv[1], len);

    return 0;
}
