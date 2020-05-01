#include <sys/regdef.h>

.text
.align 2

/* int atoi_loop(char* s , int sign) */
.globl atoi_loop
.ent atoi_loop

atoi_loop:
    subu sp, sp, 24
    /* SRA */
    sw gp, 20(sp)
    sw fp, 16(sp)

    move fp, sp
    
    sw a0, 24(fp)
    sw a1, 28(fp)

    /* LTA */
    sw zero, 0(fp)
    lw t0, 24(fp)
    sw t0, 8(fp)

L_LOOP:
    lw t0, 8(fp)
    lbu t1, 0(t0)

    beqz t1, L_RET
    
    lw t0, 8(fp)
    lbu t0, 0(t0)
    li t1, '0'
    subu t0, t0, t1
    sw t0, 4(fp) /* *p - '0' */

    lw t0, 0(fp)
    li t1, 10
    mul t0, t0, t1 /* acc * 10 */

    lw t1, 4(fp)
    lw t0, 0(fp)
    add t0, t0, t1
    sw t0, 0(fp) /* acc = acc * 10 + (*p - '0') */

    lw t0, 8(fp)
    addiu t0, t0, 1
    sw t0, 8(fp)

    b L_LOOP 

L_RET:
    lw v0, 0(fp)    
    lw t0, 28(fp)
    mul v0, v0, t0 /* acc * sign */
    
    /* Stack unwinding */
    lw fp, 16(sp)
    lw gp, 20(sp)

    addiu sp, sp, 24
    jr ra
.end atoi_loop
