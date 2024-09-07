.global loop_s

# Arguments
# a0 - int n

# Register usage
# t0 - int i
# t1 - int sum

loop_s:
    li t0, 0          # t0 = 0 (i = 0)
    li t1, 0          # t1 = 0 (sum = 0)

loop:
    bge t0, a0, done  # if t0 >= a0 branch to done label
    add t1, t1, t0    # t1 = t1 + t0 (sum = sum + i)
    addi t0, t0, 1    # t0 = t0 + 1 (i = i + 1)
    j loop            # jump to loop label to repeat loop
done:
    mv a0, t1         # a0 = t1 (return value in a0)
    ret
