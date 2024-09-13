.global inrange_s

# a0 - int x
# a1 - int a
# a2 - int b

inrange_s:

    # In this case we write the branch so that
    # we consider each of the "and" conditions
    # We ask for each condition if it is "false",
    # and, if so, then branch to the "else". 
    
    blt a0, a1, inrange_else    # Is x < a? If so, then go to else
    bgt a0, a2, inrange_else    # Is x > b? If so, then go to else

    li t0, 1
    j inrange_done

inrange_else:
    li t0, 0    

inrange_done:
    mv a0, t0
    ret
