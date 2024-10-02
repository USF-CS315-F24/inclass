.global main


jal_s:
    ret

main:
    addi sp, sp, -16
    sd ra, (sp)
    
    call jal_s

    ld ra, (sp)
    addi sp, sp, 16
    ret
    
