#include <mips/regdef.h>

#define SS 8
#define RSA_FP 4
#define RSA_GP 0

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
         move t5, a0	
         
         /* while (*p++); */
L$CMP:   lbu t1, 0(t5)

      	 beqz t1, L$RET

      	 addiu t5, t5, 1
      	 b L$CMP

         /* p - s - 1 */
L$RET:   
         lw t0, SS($fp) # s
         
         subu v0, t5, t0
         subu v0, v0, 1
         
         lw gp, RSA_GP($fp)
         lw $fp, RSA_FP(sp)
         
         addiu sp, sp, SS
         
         jr ra
         
         .end strlen
