
CC_FLAGS = -g -O0 -mips32 -mlong32 -mabi=32

all: c_encode mips_encode

c_encode: base64.o encode.c
	gcc $(CC_FLAGS) $^ -o $@
mips_encode: base64.o encode.S
	gcc $(CC_FLAGS) $^ -o $@

base64.o: base64.c
	gcc -c $(CC_FLAGS) $^ -o $@
clean:
	rm c_encode mips_encode *.o
