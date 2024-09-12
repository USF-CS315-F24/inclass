.global add4f_s

# a0 - int a
# a1 - int b
add2_s:
    add a0, a0, a1
    ret

# a0 - int a
# a1 - int b
# a2 - int c
# a3 - int d
#
# t0 - int tmp0

# We use a caller-saved register approach.
# This means that before we make a call,
# we save any caller-saved registers we need
# to preserve on the stack (a0-a7,t0-t6),
# and restore them after the call. We only have
# preserve caller-saved registers that we care
# about

add4f_s:
    addi sp, sp, -32    # sp must always be a multiple of 16
    sd ra, (sp)         # Preserve ra on stack

    sd a2, 8(sp)        # Preserve a2 (c) on stack
    sd a3, 16(sp)       # Preserve a3 (d) on stack

    call add2_s         # add2_c(a, b)

    mv t0, a0           # t0 = a0 (result of add2_c(a, b))

    ld a0, 8(sp)        # Restore a2 from stack into a0
    ld a1, 16(sp)       # Restore a3 from stack into a1
    sd t0, 8(sp)        # Preserve t0 on stack

    call add2_s         # add2_c(c, d)

    mv a1, a0           # a1 (tmp1) = a0
    ld a0, 8(sp)        # a0 = tmp0 from stack
    
    call add2_s         # add2_c(tmp0, tmp1)

    ld ra, (sp)         # Restore ra from stack
    addi sp, sp, 32     # Deallocate stack
    ret
