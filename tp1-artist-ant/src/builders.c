#include "builders.h"
#include <strings.h>

colour_t
get_colour(char c)
{
  static char * index = COLOURS;

  char *p = strchr(index, c);

  if (!p){
    return COLOUR_NOT_FOUND;
  }

  return (p - index);
}