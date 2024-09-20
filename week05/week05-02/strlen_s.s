# strlen() in Assembly

.global strlen_s

# a0 - char *s
# t0 - int len

strlen_s:
    li t0, 0

strlen_while:
    lb t1, (a0)                # t1 = *a0
    beq t1, zero, strlen_done
    addi t0, t0, 1
    addi a0, a0, 1             # Only need to increment by 1 byte
    j strlen_while
strlen_done:
    mv a0, t0
    ret
