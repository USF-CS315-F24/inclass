#include <stdint.h>
#include "bits.h"

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

bool get_bit(uint64_t num, uint32_t which) {
    return (num >> which) & 0b1;
}
