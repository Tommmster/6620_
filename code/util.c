#include <string.h>

unsigned int 
length(const char *s) 
{
  return strlen(s);
}

unsigned int 
get_digit(char c) 
{
  return c - '0';  
}

int
isdigit(char c)
{
 return c > '0' && c<'9';
}
