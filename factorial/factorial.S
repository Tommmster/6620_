#include <mips/regdef.h>

	.text
	.globl factorial
	.align 2

	.ent factorial

factorial:
	subu	sp,sp,40
	
	sw	ra,32(sp)	//Saved Registers Area.
	sw	$fp,28(sp)
	sw	gp,24(sp)
	move	$fp,sp

	sw	a0,40($fp)	//Argument building area.
	sw	a0,16($fp)	//Local and temporary area
	
	lw	t0,16($fp)
	li	t1,2
	sltu	t2,t0,t1	 
	bgtz 	t2,$RET1	

$CALL:	//factorial(n-1)	
	lw	t0,16($fp)
	subu	t0,t0,1
	sw	t0,16($fp)
	
	lw	a0,16($fp)

	la	t9,factorial
	jalr	t9

	lw	t0,40($fp)
	mul	v0,v0,t0	// n * (n-1)!
	b	$UNW
	
	//return 1	
$RET1:	li	v0,1

$UNW:	//Stack unwinding
	
	lw	ra,32(sp)
	lw	$fp,28(sp)

	addiu	sp,sp,40
	jr	ra
	
	.end	factorial
	
