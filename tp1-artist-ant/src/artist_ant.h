#ifndef __ARTIST_ANT_H__
#define __ARTIST_ANT_H__

#include <unistd.h>

#define NORTH ((uint32_t) 0)
#define SOUTH ((uint32_t) 1)
#define EAST ((uint32_t) 2)
#define WEST ((uint32_t) 3)

typedef struct {
    uint32_t x, y;
    uint32_t o;
} ant_t;

typedef struct {
    uint32_t width;
    uint32_t height;
    uint32_t **grid;
} square_grid_t;

typedef struct {
    unsigned char *palette;
    uint32_t i;
} palette_t;

void* paint(void *ant, void *grid, void *palette, void *rules,  uint32_t iterations);

void* make_grid(uint32_t , uint32_t, uint32_t );

void* make_palette(unsigned char*);

void* make_ant(uint32_t xini, uint32_t yini);

void grid_out();

uint32_t as_int(void *arg, uint32_t from, uint32_t to);

#endif

