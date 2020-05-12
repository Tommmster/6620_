#include <stdio.h>
#define N(x) *(&(x) + 1)
void 
foo(void)
{
    /* a */
    int a = 13;
    /* b */
    int b = 1345;
    /* c */
    int c = 17;
    /* d */
    int d = 7;

    printf("%d %d %d %d\n",N(a), N(b), N(c), N(d));
}

int 
main(void)
{
  foo();
  return 0;
}
