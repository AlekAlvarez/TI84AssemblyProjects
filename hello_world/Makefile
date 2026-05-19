# Variables
NAME = DEMO
SRC = src
BIN = bin
OUT=output
# Tools
CC = sdcc
AS = spasm
# CFLAGS: -mz80 (target Z80), --no-std-crt0 (we provide our own startup)
CFLAGS = -mz80 --no-std-crt0 --code-loc 0x9D95

all:
	mkdir -p $(BIN)
	mkdir -p $(OUT)
	# 1. Compile C to Assembly
	$(CC) $(CFLAGS) -S $(SRC)/main.c -o $(OUT)/main_c.asm
	
	# 2. Translate Dialects (The Cleanup)
	# Remove .area, .module, .opts, and .globl lines
	sed -i '/\.area/d; /\.module/d; /\.opts/d; /\.globl/d' $(OUT)/main_c.asm
	
	# Change SDCC hex '0x' to SPASM hex '$'
	sed -i 's/0x/\$$/g' $(OUT)/main_c.asm
	# NEW: Change double-colons (::) to single colons (:)
	sed -i 's/::/:/g' $(OUT)/main_c.asm
	# 3. Assemble using your Glue file
	$(AS) $(SRC)/linked.asm $(BIN)/$(NAME).8xp -I $(SRC)
	
clean:
	rm -rf $(BIN)/*
	rm -rf $(OUT)/*