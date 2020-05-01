#include <sys/regdef.h>

.text
.align 2

/* int ratoi(int acc, char* e , int sign) */
.globl ratoi
.ent ratoi

ratoi:
    subu sp, sp, 40
    /* SRA */
    sw ra, 32(sp)
    sw gp, 28(sp)
    sw fp, 24(sp)

    move fp, sp
    
    /* Store arguments in caller ABA */
    sw a0, 40(fp)
    sw a1, 44(fp)
    sw a2, 48(fp)

    /* *e ? 0 */
    lw t0, 44(fp)
    lbu t0, 0(t0)
    bnez t0, L_else

    lw t0, 40(fp)
    lw t1, 48(fp)
    mul t0, t0, t1 
    move v0, t0 /* acc * sign */
    b L_RET

L_else:
    /* i = *e - '0' */
    lw t0, 44(fp)
    lbu t0, 0(t0) 
    li t1, '0'

    subu t1, t0, t1 
    sw t1, 16(fp) /* i */
    
    lw t0, 40(fp)
    li t1, 10
    mul t0, t0, t1

    lw t1, 16(fp)
    add t0, t0, t1 
    move a0, t0 /* acc * 10 + i */

    lw t0, 44(fp)
    addiu t0, t0, 1 
    move a1, t0 /* e + 1 */
    
    lw t0, 48(fp)
    move a2, t0 /* sign */

    jal ratoi

L_RET:
    
    /* Stack unwinding */
    lw fp, 24(sp)
    lw gp, 28(sp)
    lw ra, 32(sp)

    addiu sp, sp, 40
    jr ra

.end ratoi
