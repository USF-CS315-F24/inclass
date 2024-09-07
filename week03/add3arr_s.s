.global add3arr_s

# Arguments
# a0 - int arr[] (address)

# Registers
# t0 - int sum
# t1 - int tmp

add3arr_s:
    lw t0, (a0)      # t0 = *a0 (get value from memory at addr a0)
    addi a0, a0, 4   # make a0 point to the next element in arr
    lw t1, (a0)      # t0 = *a0 (get arr[1])
    add t0, t0, t1   # t0 = t0 + t1 (sum = sum + tmp)
    addi a0, a0, 4   # go to next element in arr
    lw t1, (a0)      # t1 = *a0 (get arr[2])
    add t0, t0, t1   # t0 = t0 + t1 (sum = sum + tmp)
    mv a0, t0        # a0 = t0 (return sum in a0)
    ret
