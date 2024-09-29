#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


#define RV_NREGS         32

#define RV_RA             1
#define RV_SP             2  
#define RV_A0            10
#define RV_A1            11
#define RV_A2            12
#define RV_A3            13

#define RV_STACK_SIZE  8192


struct rv_state {
    uint64_t regs[RV_NREGS];
    uint64_t pc;
    uint8_t stack[RV_STACK_SIZE];
};

void unsupported(char *s, uint32_t val) {
    printf("%s: %d\n", s, val);
    exit(-1);
}

uint32_t get_bits(uint64_t num, uint32_t start, uint32_t count) {
    uint64_t mask = (1 << count) - 1;
    return (num >> start) & mask;
}

int64_t sign_extend(uint64_t num, uint32_t start) {
    uint32_t dist = 64 - start;
    uint64_t shifted_bits = num << dist;
    int64_t signed_bits = ((int64_t) shifted_bits) >> dist;
    return signed_bits;
}

static uint32_t get_opcode(uint32_t iw) {
    return get_bits(iw, 0, 7);
}

static uint32_t get_rd(uint32_t iw) {
    return get_bits(iw, 7, 5);
}

static uint32_t get_funct3(uint32_t iw) {
    return get_bits(iw, 12, 3);
}

static uint32_t get_funct7(uint32_t iw) {
    return get_bits(iw, 25, 7);
}

static uint32_t get_rs1(uint32_t iw) {
    return get_bits(iw, 15, 5);
}

static uint32_t get_rs2(uint32_t iw) {
    return get_bits(iw, 20, 5);
}


int add2_c(int64_t a, int64_t b);
int add2_s(int64_t a, int64_t b);

void rv_init(struct rv_state *rsp, uint32_t *func,
             uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3){
    // Zero out registers
    for (int i = 0; i < RV_NREGS; i++) {
        rsp->regs[i] = 0;
    }

    // Zero out stack
    for (int i = 0; i < RV_STACK_SIZE; i++) {
        rsp->stack[i] = 0;
    }
    
    // Initialize the PC
    rsp->pc = (uint64_t) func;

    // Initialize RA
    rsp->regs[RV_RA] = 0;

    // Initialize the first 4 arguments
    rsp->regs[RV_A0] = a0;
    rsp->regs[RV_A1] = a1;
    rsp->regs[RV_A2] = a2;
    rsp->regs[RV_A3] = a3;

    // Initialize the stack pointer
    rsp->regs[RV_SP] = (uint64_t) &rsp->stack[RV_STACK_SIZE];
}

void emu_r_type(struct rv_state *rsp, uint32_t iw) {
    uint32_t rd = get_rd(iw);
    uint32_t rs1 = get_rs1(iw);
    uint32_t rs2 = get_rs2(iw);
    uint32_t funct3 = get_funct3(iw);
    uint32_t funct7 = get_funct7(iw);

    if (funct3 == 0b000 && funct7 == 0b0000000) {
        // ADD
        rsp->regs[rd] = rsp->regs[rs1] + rsp->regs[rs2];
    } else {
        unsupported("R-type funct3", funct3);
    }

    rsp->pc += 4; // Next instruction
}

void emu_jalr(struct rv_state *rsp, uint32_t iw) {
    uint32_t rd = get_rd(iw);
    uint32_t rs1 = get_rs1(iw);
    uint32_t imm_unsigned = get_bits(iw, 20, 12);
    int64_t imm = sign_extend(imm_unsigned, 12);

    if (rd != 0) {
        rsp->regs[RV_RA] = rsp->pc + 4;
    }

    rsp->pc = rsp->regs[rs1] + imm;
}

void rv_one(struct rv_state *rsp) {
    uint32_t *pc = (uint32_t *) rsp->pc;
    uint32_t iw = *pc;

    uint32_t opcode = get_opcode(iw);

    switch (opcode) {
        case 0b0110011:   // r-type
            emu_r_type(rsp, iw);
            break;
        case 0b1100111:
            emu_jalr(rsp, iw);
            break;
        default:
            unsupported("Unknown opcode: ", opcode);
    }    
}

int rv_emulate(struct rv_state *rsp) {
    while (rsp->pc != 0) {
        rv_one(rsp);
    }

    return (int) rsp->regs[RV_A0];
}



int main(int argc, char *argv[]) {
    int r;
    struct rv_state state;

    r = add2_c(3, 4);
    printf("C: %d\n", r);

    r = add2_s(3, 4);
    printf("Asm: %d\n", r);

    rv_init(&state, (uint32_t *) add2_s, 3, 4, 0, 0);
    r = rv_emulate(&state);
    printf("Emu: %d\n", r);
}
