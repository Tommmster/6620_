	.file	1 "my_atoi.c"
	.section .mdebug.abi32
	.previous
	.nan	legacy
	.module	fp=xx
	.module	nooddspreg
	.abicalls
	.text
	.align	2
	.globl	my_atoi
	.set	nomips16
	.set	nomicromips
	.ent	my_atoi
	.type	my_atoi, @function
my_atoi:
	.frame	$fp,40,$31		# vars= 8, regs= 2/0, args= 16, gp= 8
	.mask	0xc0000000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.cpload	$25
	.set	nomacro
	addiu	$sp,$sp,-40
	sw	$31,36($sp)
	sw	$fp,32($sp)
	move	$fp,$sp
	.cprestore	16
	sw	$4,40($fp)
	lw	$2,40($fp)
	lb	$3,0($2)
	li	$2,45			# 0x2d
	beq	$3,$2,$L2
	nop

	lw	$2,40($fp)
	lb	$3,0($2)
	li	$2,43			# 0x2b
	bne	$3,$2,$L3
	nop

$L2:
	lw	$2,40($fp)
	addiu	$2,$2,1
	sw	$2,24($fp)
	lw	$4,24($fp)
	lw	$2,%call16(atoi_loop)($28)
	move	$25,$2
	.reloc	1f,R_MIPS_JALR,atoi_loop
1:	jalr	$25
	nop

	lw	$28,16($fp)
	sw	$2,28($fp)
	lw	$2,40($fp)
	lb	$3,0($2)
	li	$2,45			# 0x2d
	bne	$3,$2,$L4
	nop

	li	$2,-1			# 0xffffffffffffffff
	b	$L5
	nop

$L4:
	li	$2,1			# 0x1
$L5:
	lw	$3,28($fp)
	mul	$2,$2,$3
	b	$L6
	nop

$L3:
	lw	$4,40($fp)
	lw	$2,%call16(atoi_loop)($28)
	move	$25,$2
	.reloc	1f,R_MIPS_JALR,atoi_loop
1:	jalr	$25
	nop

	lw	$28,16($fp)
$L6:
	move	$sp,$fp
	lw	$31,36($sp)
	lw	$fp,32($sp)
	addiu	$sp,$sp,40
	jr	$31
	nop

	.set	macro
	.set	reorder
	.end	my_atoi
	.size	my_atoi, .-my_atoi
	.rdata
	.align	2
$LC0:
	.ascii	"\000"
	.align	2
$LC1:
	.ascii	"my_atoi(''):  %d\012\000"
	.align	2
$LC2:
	.ascii	"1\000"
	.align	2
$LC3:
	.ascii	"my_atoi('1'):  %d\012\000"
	.align	2
$LC4:
	.ascii	"+1\000"
	.align	2
$LC5:
	.ascii	"my_atoi('+1'):  %d\012\000"
	.align	2
$LC6:
	.ascii	"-9\000"
	.align	2
$LC7:
	.ascii	"my_atoi('-9'): %d\012\000"
	.align	2
$LC8:
	.ascii	"1521\000"
	.align	2
$LC9:
	.ascii	"my_atoi('1521'): %d\012\000"
	.align	2
$LC10:
	.ascii	"-3501\000"
	.align	2
$LC11:
	.ascii	"my_atoi('-3501'): %d\012\000"
	.text
	.align	2
	.globl	main
	.set	nomips16
	.set	nomicromips
	.ent	main
	.type	main, @function
main:
	.frame	$fp,32,$31		# vars= 0, regs= 2/0, args= 16, gp= 8
	.mask	0xc0000000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.cpload	$25
	.set	nomacro
	addiu	$sp,$sp,-32
	sw	$31,28($sp)
	sw	$fp,24($sp)
	move	$fp,$sp
	.cprestore	16
	lw	$2,%got($LC0)($28)
	addiu	$4,$2,%lo($LC0)
	lw	$2,%got(my_atoi)($28)
	move	$25,$2
	.reloc	1f,R_MIPS_JALR,my_atoi
1:	jalr	$25
	nop

	lw	$28,16($fp)
	move	$5,$2
	lw	$2,%got($LC1)($28)
	addiu	$4,$2,%lo($LC1)
	lw	$2,%call16(printf)($28)
	move	$25,$2
	.reloc	1f,R_MIPS_JALR,printf
1:	jalr	$25
	nop

	lw	$28,16($fp)
	lw	$2,%got($LC2)($28)
	addiu	$4,$2,%lo($LC2)
	lw	$2,%got(my_atoi)($28)
	move	$25,$2
	.reloc	1f,R_MIPS_JALR,my_atoi
1:	jalr	$25
	nop

	lw	$28,16($fp)
	move	$5,$2
	lw	$2,%got($LC3)($28)
	addiu	$4,$2,%lo($LC3)
	lw	$2,%call16(printf)($28)
	move	$25,$2
	.reloc	1f,R_MIPS_JALR,printf
1:	jalr	$25
	nop

	lw	$28,16($fp)
	lw	$2,%got($LC4)($28)
	addiu	$4,$2,%lo($LC4)
	lw	$2,%got(my_atoi)($28)
	move	$25,$2
	.reloc	1f,R_MIPS_JALR,my_atoi
1:	jalr	$25
	nop

	lw	$28,16($fp)
	move	$5,$2
	lw	$2,%got($LC5)($28)
	addiu	$4,$2,%lo($LC5)
	lw	$2,%call16(printf)($28)
	move	$25,$2
	.reloc	1f,R_MIPS_JALR,printf
1:	jalr	$25
	nop

	lw	$28,16($fp)
	lw	$2,%got($LC6)($28)
	addiu	$4,$2,%lo($LC6)
	lw	$2,%got(my_atoi)($28)
	move	$25,$2
	.reloc	1f,R_MIPS_JALR,my_atoi
1:	jalr	$25
	nop

	lw	$28,16($fp)
	move	$5,$2
	lw	$2,%got($LC7)($28)
	addiu	$4,$2,%lo($LC7)
	lw	$2,%call16(printf)($28)
	move	$25,$2
	.reloc	1f,R_MIPS_JALR,printf
1:	jalr	$25
	nop

	lw	$28,16($fp)
	lw	$2,%got($LC8)($28)
	addiu	$4,$2,%lo($LC8)
	lw	$2,%got(my_atoi)($28)
	move	$25,$2
	.reloc	1f,R_MIPS_JALR,my_atoi
1:	jalr	$25
	nop

	lw	$28,16($fp)
	move	$5,$2
	lw	$2,%got($LC9)($28)
	addiu	$4,$2,%lo($LC9)
	lw	$2,%call16(printf)($28)
	move	$25,$2
	.reloc	1f,R_MIPS_JALR,printf
1:	jalr	$25
	nop

	lw	$28,16($fp)
	lw	$2,%got($LC10)($28)
	addiu	$4,$2,%lo($LC10)
	lw	$2,%got(my_atoi)($28)
	move	$25,$2
	.reloc	1f,R_MIPS_JALR,my_atoi
1:	jalr	$25
	nop

	lw	$28,16($fp)
	move	$5,$2
	lw	$2,%got($LC11)($28)
	addiu	$4,$2,%lo($LC11)
	lw	$2,%call16(printf)($28)
	move	$25,$2
	.reloc	1f,R_MIPS_JALR,printf
1:	jalr	$25
	nop

	lw	$28,16($fp)
	move	$2,$0
	move	$sp,$fp
	lw	$31,28($sp)
	lw	$fp,24($sp)
	addiu	$sp,$sp,32
	jr	$31
	nop

	.set	macro
	.set	reorder
	.end	main
	.size	main, .-main
	.ident	"GCC: (Debian 6.3.0-18+deb9u1) 6.3.0 20170516"
