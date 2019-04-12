#include "ant_engine.h"

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


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
  char *s = "R|W";

  char *r = "01";
  panic("Implement me!");
  return NULL;
}

