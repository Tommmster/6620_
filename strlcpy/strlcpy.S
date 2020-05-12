#include<sys/regdef.h>

#define SS 24

#define O_GP 20
#define O_FP 16

#define O_LTA_D 0
#define O_LTA_S 4
#define O_LTA_N 8

#define O_A0 (SS)
#define O_A1 (O_A0 + 4)
#define O_A2 (O_A1 + 4)

.text
.align 2


/*
size_t
strlcpy(char *dst, const char *src, size_t siz)
*/ 

.globl strlcpy
.ent strlcpy

strlcpy:
    subu sp, sp, SS
    sw   gp, O_GP(sp)
    sw   fp, O_FP(sp)
    move fp, sp

    sw   a0, O_A0(fp)
    sw   a1, O_A1(fp)
    sw   a2, O_A2(fp)


    /* Local and temporary area */
    /* d = dst */

    lw t0, O_A0(fp)
    sw t0, O_LTA_D(fp)

    /* s = src */
    lw t0, O_A1(fp)
    sw t0, O_LTA_S(fp)
    
    /* n = siz */
    lw t0, O_A2(fp)
    sw t0, O_LTA_N(fp)

    /* TODO: Implementar */


    /* return (s - src - 1) */
    lw v0, O_LTA_S(fp)
    lw t0, O_A1(fp)

    addiu t0, t0, 1
    subu  v0, v0, t0

    /* Stack unwinding */
    lw fp, O_FP(sp)
    lw gp, O_GP(sp)
    addiu sp, sp, SS

    jr ra
.end strlcpy

/* compile with gcc -mips32 -mlong32 -mabi=32 -c strlcpy.S */
