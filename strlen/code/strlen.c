#include <unistd.h>

size_t
strlen(const char *s)
{
  char *p = s;

  while (*p++);

  return p - s - 1;
}
