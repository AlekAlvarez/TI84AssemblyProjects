_HomeUp:      .equ $4528
_ClrLCDFull:  .equ $4540
_PutS:        .equ $450A
_GetKey:      .equ $4972

#define bcall(addr) rst 28h \ .dw addr