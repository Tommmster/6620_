#ifndef __ARTIST_ANT_H__
#define __ARTIST_ANT_H__

#include <unistd.h>
typedef enum colour {RED, GREEN, BLUE, YELLOW, BLACK, WHITE} colour_t;
typedef enum orientation {NORTH, SOUTH, EAST, WEST} orientation_t;
typedef enum rotatioin {LEFT, RIGHT} rotation_t;

typedef struct {
    uint32_t x, y;
    orientation_t o;
} ant_t;

typedef struct {
    uint32_t width;
    uint32_t height;
    colour_t **grid;
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

