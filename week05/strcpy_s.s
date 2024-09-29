# strcpy() in Assembly

.global strcpy_s

# a0 = char *dst
# a1 = char *src

# t0 = int i;

strcpy_s:
    li t0, 0

strcpy_loop:
    add t1, a1, t0             # t2 = a1 (src) + t0 (i)
    lb t2, (t1)
    beq t2, zero, strcpy_done

    add t3, a0, t0             # t3 = a0 (dst) + t0 (i)
    sb t2, (t3)

    addi t0, t0, 1             # t0 = t0 (i) + 1
    j strcpy_loop

strcpy_done:
    add t3, a0, t0             # t3 = a0 (dst) + t0 (i)
    sb zero, (t3)
    ret
