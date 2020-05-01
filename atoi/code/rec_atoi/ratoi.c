#include <stdio.h> 

int my_atoi(char *);
#ifndef USE_MIPS32

static int
ratoi(int acc, char *e, int sign)
{
  unsigned int i;

  if (! *e ){
      return sign * acc;
  }
  else {
      /* go recursive */
      i =  *e - '0';
      return ratoi( acc * 10 + i, e + 1, sign);
  }
}
#else /* USE_MIPS32 */
extern int ratoi(int, char*, int);
#endif

int
my_atoi(char *s)
{
  char *start_at;
  if (s[0] == '-') {
      start_at = s + 1;
      return ratoi( *start_at - '0', start_at + 1, -1);
  }
  else {
      return ratoi(*s - '0', s + 1, 1);
  }
}


int 
main(void) 
{
    printf("my_atoi('1'):  %d\n", my_atoi("1"));
    printf("my_atoi('-9'): %d\n", my_atoi("-9"));
    printf("my_atoi('1521'): %d\n", my_atoi("1521"));
    printf("my_atoi('-3501'): %d\n", my_atoi("-3501"));

    return 0;
}

