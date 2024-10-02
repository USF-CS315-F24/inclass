#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "rv_emu.h"
#include "bits.h"

#define DEBUG 0

void unsupported(char *s, uint32_t val) {
    printf("%s: %d\n", s, val);
    exit(-1);
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

void rv_init(struct rv_state *rsp, uint32_t *func,
             uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3) {
    int i;

    // Zero out registers
    for (i = 0; i < RV_NREGS; i += 1) {
        rsp->regs[i] = 0;
    }

    // Zero out the stack
    for (i = 0; i < RV_STACK_SIZE; i += 1) {
        rsp->stack[i] = 0;
    }

    // Initialize the Program Counter
    rsp->pc = (uint64_t) func;

    // Initialize the Link Register to a sentinel value
    rsp->regs[RV_RA] = 0;

    // Initialize Stack Pointer to the logical bottom of the stack
    rsp->regs[RV_SP] = (uint64_t) &rsp->stack[RV_STACK_SIZE];

    // Initialize the first 4 arguments in emulated r0-r3
    rsp->regs[RV_A0] = a0;
    rsp->regs[RV_A1] = a1;
    rsp->regs[RV_A2] = a2;
    rsp->regs[RV_A3] = a3;
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

    // Get an instruction word from the current Program Counter    
    uint32_t iw = *(uint32_t*) rsp->pc;

    uint32_t opcode = get_opcode(iw);

    switch (opcode) {
        case FMT_R:
            // R-type
            emu_r_type(rsp, iw);
            break;
        case FMT_I_JALR:
            // JALR (aka RET) is a variant of I-type instructions
            emu_jalr(rsp, iw);
            break;
        default:
            unsupported("Unknown opcode: ", opcode);
            
    }
}

int rv_emulate(struct rv_state *rsp) {
    uint64_t inst_count = 0;

    while (rsp->pc != 0 && inst_count < RV_MAX_INST_COUNT) {
        rv_one(rsp);
        inst_count += 1;
    }
    
    return (int) rsp->regs[RV_A0];
}
