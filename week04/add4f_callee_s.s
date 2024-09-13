.global add4f_callee_s

# Add two args
#
# a0 - int a
# a1 - int b
add2_s:
    add a0, a0, a1
    ret

# Add four args
#
# a0 - int a
# a1 - int b
# a2 - int c
# a3 - int d

# s0 - int a2
# s1 - int a3
# s2 - int tmp0
# s3 - int tmp1

# We use a callee-saved register approach.
# This means we can rely on s registers
# being preserves accross function calls.
# However, since we are also a "callee", we
# need to preserve any s register we use at
# the beginning of the function and restore
# them before we return.

add4f_callee_s:
    addi sp, sp, -48    # Must be a multiple of 16    
    sd ra, (sp)         # Preserve ra on stack
    sd s0, 8(sp)        # Preserve s0-s3 on stack
    sd s1, 16(sp)
    sd s2, 24(sp)
    sd s3, 32(sp)

    mv s0, a2           # s0 = a2 (c)
    mv s1, a3           # s1 = a3 (d)
    
    call add2_s         # add2_c(a, b)

    mv s2, a0           # s2 (tmp0) = a0 (add2_c(a, b))
    mv a0, s0           # a0 = s0 (c)
    mv a1, s1           # a1 = s1 (d)
    
    call add2_s         # add2_c(c, d)

    mv s3, a0           # s3 (tmp1) = a0 (add2_c(c, d))
    mv a0, s2           # a0 = s2 (tmp0)
    mv a1, s3           # a1 = s2 (tmp1)

    call add2_s         # add2_c(tmp0, tmp1)

    ld s3, 32(sp)       # Restore s0-s3 from stack
    ld s2, 24(sp)
    ld s1, 16(sp)
    ld s0, 8(sp)
    ld ra, (sp)         # Restore ra from stack
    addi sp, sp, 48     # Deallocate stack
    ret
