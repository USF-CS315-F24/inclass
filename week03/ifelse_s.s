.global ifelse_s

# I create a legend to map registers to C variables
# a0 - val    (argument)
# t0 - retval

ifelse_s:
    # if (val > 0) {
    # We need to reverse the notion of the condition
    # to branch if val <= 0
    ble a0, zero, else   # is a0 <= 0? If so branch to else label
    li t0, 1             # t0 = 1
    j done               # jump to done label
else:
    li t0, 0             # t0 = 0
    # Here we just fall through to the mv instruction
done:
    mv a0, t0            # a0 = t0 (return value in a0)
    ret
