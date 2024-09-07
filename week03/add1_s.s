# The .global directive makes the add1_s label public
# This allow code in other files call this function.
.global add1_s

# A convetion I use is to map out how registers are used:

# int a - a0

# In this case I am saying a0 represent the arg int a

# add1_s is a label. In this case it designates the beginning
# of a function.
add1_s:
    addi a0, a0, 1
    # The return value goes in a0
    # By convention, the caller of this function expects
    # the return value to be in a0.
    ret
