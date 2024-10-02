#include <stdint.h>
#include <stdbool.h>

uint32_t get_bits(uint64_t num, uint32_t start, uint32_t count);
int64_t sign_extend(uint64_t num, uint32_t start);
bool get_bit(uint64_t num, uint32_t which);
