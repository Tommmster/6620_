
GCC_FLAGS = -g -O0 -mips32 -mlong32 

all: rec_atoi rec_atoi_mips loop_atoi loop_atoi_mips loop_atoi_mips_wrapper

build_rec_atoi_mips:
	cd rec_atoi; make rec_atoi_mips

build_rec_atoi:
	cd rec_atoi; make rec_atoi

build_loop_atoi_mips:
	cd loop_atoi; make atoi_loop_mips

build_loop_atoi:
	cd loop_atoi; make atoi_loop

rec_atoi_mips: build_rec_atoi_mips my_atoi.c 
	gcc -DUSE_REC_ATOI $(GCC_FLAGS) my_atoi.c rec_atoi/rec_atoi_mips.o -o ratoi_mips

rec_atoi: build_rec_atoi my_atoi.c 
	gcc -DUSE_REC_ATOI $(GCC_FLAGS) my_atoi.c rec_atoi/rec_atoi.o -o ratoi

loop_atoi: build_loop_atoi my_atoi.c
	gcc $(GCC_FLAGS) my_atoi.c loop_atoi/atoi_loop.o -o latoi

loop_atoi_mips: build_loop_atoi_mips my_atoi.c
	gcc $(GCC_FLAGS) my_atoi.c loop_atoi/atoi_loop_mips.o -o latoi_mips

loop_atoi_mips_wrapper: build_loop_atoi_mips my_atoi_mips_loop.S my_atoi.c
	gcc $(GCC_FLAGS) -DUSE_MIPS32 my_atoi.c my_atoi_mips_loop.S loop_atoi/atoi_loop_mips.o -o latoi_mips_wrapper

clean:
	cd loop_atoi; make clean
	cd rec_atoi; make clean
	rm latoi latoi_mips ratoi ratoi_mips
