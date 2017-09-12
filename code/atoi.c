#include <stdio.h>

extern int simple_atoi(const char *a);

int 
main(int argc, char **argv)
{
  char *a = NULL;

  if (argc == 1){
    a = "123";
  }
  else {
    a = argv[1];
  }
  int d = simple_atoi(a);

  printf ("N is %d \n", d);

  return 0;
}
