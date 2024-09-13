.global factrec_s

# Compute n! using recursion

# a0 = int n

factrec_s:
    addi sp, sp, -16            # Allocate stack space for ra and a0 (n)
    sd ra, (sp)                 # Save ra on stack

    bne a0, zero, factrec_else  # Base case check
    li a0, 1
    j factrec_done

factrec_else:

    sd a0, 8(sp)                # Save a0 (n) on stack
    addi a0, a0, -1             # a0 (n) = a0 (n) - 1
    call factrec_s              # Recursive call

    ld t0, 8(sp)                # t0 = a0 (n)
    mul a0, a0, t0              # a0 = a0 (factrec_c(n-1)) * t0 (n)

factrec_done:

    ld ra, (sp)                 # Restore ra from stack
    addi sp, sp, 16             # Deallocate stack
    ret
