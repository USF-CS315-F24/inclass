#include <stdio.h>
#include <stdint.h>

int add2_s(int a, int b);

int main(int argc, char *argv[]) {
    int r;

    r = add2_s(3, 4);
    printf("add2_s(3, 4) = %d\n", r);

    uint32_t iw;    // instruction word
    uint32_t *pc;   // program counter

    pc = (uint32_t *) add2_s;
    iw = *pc;

    printf("[pc = %p] iw = 0x%08x\n", pc, iw);

    uint32_t opcode;
    uint32_t funct3;
    uint32_t funct7;
    uint32_t rd;
    uint32_t rs1;
    uint32_t rs2;

    opcode = iw & 0b1111111;
    funct3 = (iw >> 12) & 0b111;
    funct7 = (iw >> 25) & 0b1111111;
    rd     = (iw >> 7) & 0b11111;
    rs1    = (iw >> 15) & 0b11111;
    rs2    = (iw >> 20) & 0b11111; 

    printf("opcode = %X\n", opcode);
    printf("funct3 = %X\n", funct3);
    printf("funct7 = %X\n", funct7);
    printf("rd     = %d\n", rd);
    printf("rs1    = %d\n", rs1);
    printf("rs2    = %d\n", rs2);

    return 0;
}
