#include <stdlib.h>

#include "ant_types.h"
#include "square_grid.h"
#include "builders.h"
#include "grid.h"

static uint32_t grid_width = 0;
static uint32_t grid_height = 0;

static square_grid_t sq_grid;
static grid_handler_t handler;

static void 
paint_at(uint32_t x, uint32_t y, colour_t c)
{
  sq_grid.grid[x][y] = c;
}

static colour_t
colour_at(uint32_t x, uint32_t y)
{
  return sq_grid.grid[x][y];
}

grid_handler_t*
make_grid(const uint32_t width,const uint32_t height,const colour_t initial)
{
	unsigned int i, j;
  sq_grid.grid = (colour_t **) xmalloc (width * sizeof(colour_t*));

  for (i = 0; i < width; i++) {
    sq_grid.grid[i] = (colour_t *) xmalloc (height * sizeof(colour_t));
    for (j = 0; j < height; j++) {
      sq_grid.grid[i][j] =  initial;
    }
  }

  return make_grid_handler(width, height);
}

static grid_handler_t*
make_grid_handler(const uint32_t width, const uint32_t height)
{
	handler.width = width;
	handler.height = height;

	handler.set = paint_at;
	handler.get = colour_at;
  

	return &handler;
}
