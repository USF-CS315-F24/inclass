#include <stdio.h>
#include <stdint.h>

int main(int argc, char *argv[]) {
    int x = 0xFFAA1122;
    uint8_t b;

    //unit8_t *bp;
    //bp = (uint8_t *) &x
    //b = *bp;

    b = *((uint8_t *) &x);

    printf("b = %X\n", b);

    return 0;
}
