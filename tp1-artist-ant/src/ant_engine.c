#include "ant_engine.h"

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define panic(s)       \
  do {                 \
    fprintf(stderr, "%s: %s\n", __FUNCTION__, s);\
    exit(1);            \
  } while(0);


void*
paint(void *ant, void *grid, void *palette, void *rules,  uint32_t iterations)
{
  panic ("Implement me!");
  return grid;
}

void*
make_rules(char *spec)
{
  panic("Implement me!");
  return NULL;
}

void*
make_palette(unsigned char *colours)
{
  panic("Implement me!");
  return NULL;
}

