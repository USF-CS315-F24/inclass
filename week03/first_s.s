# The .global directive allow a label to be seen by other code
# main needs to be global when we link it to become an executable
.global main

# Labels designate addresses in memory. When the final machine
# code is loaded into memory the code will live at a specific
# address. Labels let us refer to addresses without having to
# know their specific values.
main:
    li t0, 3        # t0 = 3
    li t1, 99       # t1 = 99
    add a0, t0, t1  # a0 = t0 + t1 (return value goes in a0)
    ret

