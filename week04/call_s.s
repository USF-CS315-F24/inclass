.global foo_s

# a0 - int a

bar_s:
    addi a0, a0, 1    
    ret

foo_s:
    addi sp, sp, -16   # Allocate 16 bytes of stack space
                       # This must be a multiple of 16
    sd ra, (sp)        # Put ra in the first 64 bit (8 byte) stack slot

    call bar_s         # ra = pc + 4; pc = bar_s (addr)
    # PC + 4

    addi a0, a0, 1     # a0 = bar_s(a0) + 1

    ld ra, (sp)        # Restore ra from stack
    addi sp, sp, 16    # Deallocate 16 bytes of stack space
    ret                # pc = ra
