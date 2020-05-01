#include <stdio.h> 
#include <ctype.h>

int my_atoi(char *);

#ifndef USE_MIPS32

static int
ratoi(int acc, char *e)
{
  unsigned int i;

  if (! *e ){
      return acc;
  }
  else {
      /* go recursive */
      i =  *e - '0';
      return ratoi( acc * 10 + i, e + 1);
  }
}
#else /* USE_MIPS32 */
extern int ratoi(int, char*);
#endif

int
my_atoi(char *s)
{
  char *start_at;

  if (*s == '-' || *s == '+') {
      start_at = s + 1;
      return (*s == '-' ? -1 : 1) * ratoi(0 , start_at);
  }
  else {
      return ratoi(0, s);
  }
}


int 
main(void) 
{
    printf("my_atoi('1'):  %d\n", my_atoi("1"));
    printf("my_atoi('+1'):  %d\n", my_atoi("+1"));
    printf("my_atoi('-9'): %d\n", my_atoi("-9"));
    printf("my_atoi('1521'): %d\n", my_atoi("1521"));
    printf("my_atoi('-3501'): %d\n", my_atoi("-3501"));

    return 0;
}

