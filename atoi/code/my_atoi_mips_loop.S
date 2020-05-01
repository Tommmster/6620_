#include <sys/regdef.h>

.text
.align 2

/* int my_atoi(char* s) */
.globl my_atoi
.ent my_atoi

my_atoi:
    subu sp, sp, 40
    /* SRA */
    sw ra, 32(sp)
    sw gp, 28(sp)
    sw fp, 24(sp)

    move fp, sp
    sw a0, 40(fp)

    /* *s == '-' || *s == '+' */
    lw t0, 40(fp)
    lbu t0, 0(t0)
    li t1, '-'
    beq t0, t1, L_SIGN

    lw t0, 40(fp)
    lbu t0, 0(t0)
    li t1, '+'
    beq t0, t1, L_SIGN

     /* No '+' nor '-' */
    lw t0, 40(fp)
    sw t0, 16(fp)
   
    li t0, 1
    sw t0, 20(fp)

    b L_ATOI_LOOP

L_SIGN:
    /* start_at */
    lw t0, 40(fp)
    addiu t0, t0, 1
    sw t0, 16(fp)

    /* sign */
    lw t0, 40(fp)
    lbu t0, 0(t0)
    li t1, '+'
    beq t0, t1, L_PLUS

    /* It's '-' */
    li t0, -1
    sw t0, 20(fp)
    b L_ATOI_LOOP
    
L_PLUS:
    li t0, 1
    sw t0, 20(fp)

L_ATOI_LOOP:
    /* atoi_loop(s) */
    lw a0, 16(fp)
    jal atoi_loop

    /*return  sign * atoi_loop(s) */
    lw t0, 20(fp)
    mul v0, v0, t0

L_RET:
    /* Stack unwinding */
    lw fp, 24(sp)
    lw gp, 28(sp)
    lw ra, 32(sp)

    addiu sp, sp, 40
    jr ra
.end my_atoi
