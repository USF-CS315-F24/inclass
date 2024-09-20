#include <stdio.h>

void strcpy_c(char *dst, char *src);
void strcpy_s(char *dst, char *src);

int main(int argc, char *argv[]) {
    char str1[1024];
    char str2[1024];

    strcpy_c(str1, argv[1]);
    printf("strcpy_c(%p, %p): str1 = %s\n", str1, argv[1], str1);

    strcpy_s(str2, argv[1]);
    printf("strcpy_s(%p, %p): str2 = %s\n", str2, argv[1], str2);

    return 0;
}
