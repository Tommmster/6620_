#include <unistd.h>

size_t
strlen(const char *s)
{
  register char *p = s;

  while (*p++);

  return p - s - 1;
}
