#include <stdio.h>

#include "struct.h"

uint32_t struct_c(struct foo_st *fp);
uint32_t struct_s(struct foo_st *fp);

int main(int argc, char *argv[]) {
    struct foo_st foo;
    uint32_t v;

    foo.a = 0x11;
    foo.value1 = 0x55443322;
    foo.b = 0x66;
    foo.value2 = 0xAA998877;

    v = struct_c(&foo);
    printf("foo_c(%p) = %X\n", &foo, v);

    v = struct_s(&foo);
    printf("foo_s(%p) = %X\n", &foo, v);

    return 0;
}
