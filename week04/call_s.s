.global foo_s

# a0 - int a

bar_s:
    addi a0, a0, 1    
    ret

foo_s:
    addi sp, sp, -16 

    sd ra, (sp)

    call bar_s
    # PC + 4

    addi a0, a0, 1    

    ld ra, (sp)
    addi sp, sp, 16
    ret
