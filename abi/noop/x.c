#include <stdio.h>
void 
foo(void)
{
    /* a */
    int a = 13;
    /* b */
    int b = -1;
    /* c */
    int c = 17;

    printf("%d\n", *(&b + 1));
}

int 
main(void)
{
  foo();
  return 0;
}
