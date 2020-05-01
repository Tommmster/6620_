#include <stdio.h> 

#ifdef USE_REC_ATOI
#include "rec_atoi/my_atoi.h"

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


#else 
#include "loop_atoi/my_atoi.h"

#ifndef USE_MIPS32
int
my_atoi(char *s)
{
  char *start_at;

  if (*s == '-' || *s == '+') {
      start_at = s + 1;
      return (*s == '-' ? -1 : 1) * atoi_loop(start_at);
  }
  else {
      return atoi_loop(s);
  }
}
#else
extern int my_atoi(char *);
#endif /* USE_MIPS32 */ 
#endif

int my_atoi(char *);

int 
main(void) 
{
    printf("my_atoi(''):  %d\n", my_atoi(""));
    printf("my_atoi('1'):  %d\n", my_atoi("1"));
    printf("my_atoi('+1'):  %d\n", my_atoi("+1"));
    printf("my_atoi('-9'): %d\n", my_atoi("-9"));
    printf("my_atoi('1521'): %d\n", my_atoi("1521"));
    printf("my_atoi('-3501'): %d\n", my_atoi("-3501"));

    return 0;
}

