// This prevents SDCC from adding 'standard' Z80 startup code
void _putchar(char c) { (void)c; } 
void _getchar(void) { }
// Declare the external assembly function
extern void hello(void);

void main(void) {
    // 1. Clear the screen using "Inline Assembly"
    // We do this because it's easier than writing a whole 
    // wrapper for a simple OS call.
    __asm
        rst 28h
        .dw $4540 ; _ClrLCDFull
        rst 28h
        .dw $4528 ; _HomeUp
    __endasm;

    // 2. Call your assembly function
    hello();

    // 3. Wait for a keypress before exiting
    __asm
        rst 28h
        .dw $4972 ; _GetKey
    __endasm;
}