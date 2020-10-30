#include <stdio.h>


int encode(char*, unsigned int);

char *out;
char *alphabet;

int
main(void)
{
  alphabet= "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
  char buf_in[3] = {'M', 'a', 'n'};
  char buf_out[4];
 
  /* Estamos usando un puntero a una variable local */
  out = (char *)&buf_out;
  encode(buf_in, 3);

  printf("%c%c%c%c", buf_out[0], buf_out[1], buf_out[2], buf_out[3]);


  return 0;
}
