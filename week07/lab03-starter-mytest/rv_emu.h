#include <stdint.h>

#define RV_MAX_INST_COUNT 1000000

#define RV_NREGS      32
#define RV_RA          1
#define RV_SP          2
#define RV_A0         10
#define RV_A1         11
#define RV_A2         12
#define RV_A3         13
#define RV_STOP        0

#define RV_STACK_SIZE 8192


// Opcodes for instr formats
typedef enum {
    FMT_R       = 0b0110011,
    FMT_I_LOAD  = 0b0000011,
    FMT_I_JALR  = 0b1100111,
    FMT_I_ARITH = 0b0010011,
    FMT_S       = 0b0100011,
    FMT_B       = 0b1100011,
    FMT_J       = 0b1101111
} rv_format;


// rv_state represents the state of the emulated RISC-V processor
struct rv_state {
    uint64_t regs[RV_NREGS];
    uint64_t pc;
    uint8_t stack[RV_STACK_SIZE];
};

// Initialize an rv_state struct with a function pointer and arguments
void rv_init(struct rv_state *rsp, uint32_t *fp,
             uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3);
int rv_emulate(struct rv_state *rsp);
