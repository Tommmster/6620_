#include <sys/regdef.h>

#define SS   40


/* SRA */
#define O_FP 36
#define O_GP 32

//LTA
/* Local */
#define O_I1 28
#define O_I2 24
#define O_I3 20
#define O_I4 16

/* Temporal */
#define I2_1 12
#define I2_2 8
#define I3_1 4
#define I3_2 0

#define O_A0 (SS)
#define O_A1 (SS + 4)

.data
.size alphabet, 64
alphabet: .ascii  "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"
  
.text
.align 2
/* 
int 
encode(char *input, unsigned int len)
*/
.globl encode
.ent   encode
encode:
  subu sp, sp, SS
  sw   fp, O_FP(sp)
  sw   gp, O_GP(sp)
  move fp, sp

  sw   a0, O_A0(fp)
  sw   a1, O_A1(fp)

  /* input[0] >> 2 */
  lw   t0, O_A0(fp)
  lbu  t0, 0(t0) 
  srl  t0, t0, 2
  sw   t0, O_I1(fp) #i1

  /* (input[0] & 0x3) << 4 */
  lw   t0, O_A0(fp)
  lbu  t1, 0(t0) 
  andi t1, t1, 0x3
  sll  t1, t1, 4 
  sw   t1, I2_1(fp)

  /* input[1] >> 4 */
  lw   t0, O_A0(fp)
  lbu  t0, 1(t0)
  srl  t0, t0, 4
  sw   t0, I2_2(fp)

  lw   t0, I2_1(fp)
  lw   t1, I2_2(fp)
  or   t0, t1, t0
  sw   t0, O_I2(fp) #i2

  /* (input[1] & 0XF ) << 4 */
  lw   t0, O_A0(fp)
  lbu  t0, 1(t0)
  andi t0, t0, 0xF
  sll  t0, t0, 4
  sw   t0, I3_1(fp)

  /* input[2] >> 6 */
  lw   t0, O_A0(fp)
  lbu  t0, 2(t0)
  srl  t0, t0, 6
  sw   t0, I3_2(fp)
  
  lw   t0, I3_1(fp)
  lw   t1, I3_2(fp)
  or   t0, t1, t0
  sw   t0, O_I3(fp) #i3

  /* input[2] & 0x3F */
  lw   t0, O_A0(fp)
  lbu  t0, 2(t0)
  andi t0, t0, 0x3F
  sw   t0, O_I4(fp) #i4

  la   v0, out
  la   v1, alphabet

  /* out[0] = alphabet[i1] */
  lw   t0, O_I1(fp)
  add  t1, t0, v1 # (alphabet + i1)
  lb   t1, 0(t1)
  sb   t1, 0(v0)

  /* out[1] = alphabet[i2] */
  lw   t0, O_I2(fp)
  add  t1, t0, v1 # (alphabet + i2)
  lb   t1, 0(t1)
  sb   t1, 1(v0)

  /* out[2] = alphabet[i3] */
  lw   t0, O_I3(fp)
  add  t1, t0, v1 # (alphabet + i3)
  lb   t1, 0(t1)
  sb   t1, 2(v0)

  /* out[3] = alphabet[i4] */
  lw   t0, O_I4(fp)
  add  t1, t0, v1 # (alphabet + i4)
  lb   t1, 0(t1)
  sb   t1, 3(v0)

return:
  li v0, 0

  /* stack unwinding */
  lw    fp, O_FP(sp)
  lw    gp, O_GP(sp)
  addiu sp, sp, SS

  jr ra
.end encode
