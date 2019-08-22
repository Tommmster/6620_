#ifndef __GRID_H__
#define __GRID_H__

#include "ant_types.h"

typedef struct {
  uint32_t width, height; 
  void (*set)(uint32_t x, uint32_t y, colour_t c);
  uint32_t (*get)(uint32_t x, uint32_t y);
} grid_handler_t; 

grid_handler_t*
make_grid(const uint32_t w,const uint32_t h,const colour_t initial);

static grid_handler_t*
make_grid_handler(const uint32_t width, const uint32_t height);

#endif
