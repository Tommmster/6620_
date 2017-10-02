#include <mips/regdef.h>

#define SS 16
#define RSA_FP 12
#define RSA_GP 8
#define STACK_P 0

	.globl strlen
	.text
	.align 2
	.ent strlen

/*
 size_t
 strlen(const char*)
*/
strlen:
         .cprestore RSA_GP 
         subu sp, sp, SS
         sw  $fp, RSA_FP(sp)
         move $fp, sp

         sw a0, SS($fp)

          /* p = s */
         lw t0, SS($fp)
         sw t0, STACK_P($fp)
         
         /* while (*p++); */
L$CMP:   lw t0, STACK_P($fp)
         lbu t1, 0(t0)

      	 beqz t1, L$RET

         lw t0, STACK_P($fp)
      	 addiu t0, t0, 1
      	 sw t0, STACK_P($fp)
      	 b L$CMP

         /* p - s - 1 */
L$RET:   lw t1, STACK_P($fp)
         lw t0, SS($fp)
         
         subu v0, t1, t0
         subu v0, v0, 1
         
         lw gp, RSA_GP($fp)
         lw $fp, RSA_FP(sp)
         
         addiu sp, sp, SS
         
         jr ra
         
         .end strlen
