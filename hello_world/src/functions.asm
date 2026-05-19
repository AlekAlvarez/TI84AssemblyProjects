



_hello:
    ld hl, msg
    bcall(_PutS)
    ret

msg:
    .db "HELLO FROM ASM", 0