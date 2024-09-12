.global arr_get_s
.global arr_set_s

# Get the value of the element at arr[i]

# a0 - int arr[]
# a1 - int i

arr_get_s:
    li t0, 4         # t0 = 4
    mul t0, a1, t0   # t0 = i * 4
    add t0, a0, t0   # t0 = a0 + (i * 4)
    lw a0, (t0)      # a0 = *t0 (arr[i])
    ret

# Update the element at arr[i] with v

# a0 - int arr[]
# a1 - int i
# a2 - int v

arr_set_s:
    li t0, 4         # t0 = 4
    mul t0, a1, t0   # t0 = i * 4
    add t0, a0, t0   # t0 = a0 + (i * 4)
    sw a2, (t0)      # *t0 (arr[i]) = a2
    ret
