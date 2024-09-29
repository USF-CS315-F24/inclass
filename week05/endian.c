#include <stdio.h>
#include <stdint.h>

int main(int argc, char *argv[]) {
    int x = 0xFFAA1122;

    int *xp = &x;
    uint8_t b;
    uint8_t *bp;
    
    bp = (uint8_t *) xp;
    b = *bp;

    // Or we can do
    // b = *((uint8_t *) &x);

    printf("b = %X\n", b);

    return 0;
}
