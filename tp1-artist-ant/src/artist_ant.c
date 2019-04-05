#include <stdio.h>
#include <unistd.h>
#include <getopt.h>

typedef struct {
    unsigned int x, y;
    unsigned int o;
} ant_t;

typedef struct {
    unsigned int width;
    unsigned int height;
    unsigned int * grid [];
} square_grid_t;

typedef struct {
    unsigned char *palette;
    unsigned int i;
} palette_t;

uint32_t grid_width;
uint32_t grid_height;

square_grid_t grid;
ant_t ant;
palette_t palette;

void *
paint(void *paint, void *grid, void *palette, uint32_t iterations)
{
    return NULL;
}

/*
* Dimensiones de la grilla (w x h)
* Paleta de colores (R|G|B|W|Y)
* Reglas (L|R ..)
* Número de iteraciones (entero positivo)
*/
int
main(int argc, char **argv)
{
  return 0;
}

static square_grid_t*
makeGrid(uint32_t w, uint32_t h)
{
    return &grid;
}

static ant_t*
makeAnt(uint32_t xini, uint32_t yini)
{
   return &ant;
}


