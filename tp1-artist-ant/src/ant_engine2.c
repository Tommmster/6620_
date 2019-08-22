#include "ant_engine.h"
#include "artist_ant.h"
#include "builders.h"

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <strings.h>

#if 0
static unsigned int palette_len;
static unsigned int rules_len;

rotation_t
rule_for_colour(void* palette, void* rules, colour_t colour) 
{
  const rotation_t *therules = (const rotation_t*) rules;
  const colour_t *colours = (const colour_t*) palette;

  colour_t *tmp = (colour_t*) colours;

  unsigned int i = 0;
  
  for (;i < palette_len; i++){
    if (colour == colours[i]){
      return therules[i];
    }
  }

  panic("Can't find rule for colour");
}

orientation_t 
new_orientation(orientation_t orientation, rotation_t rule)
{
  orientation_t rotation_rules[4][2] = {
    {WEST,EAST},    /* North */
    {EAST,WEST},    /* South */
    {NORTH, SOUTH}, /* East */
    {SOUTH,NORTH}   /* West */
  };

  return rotation_rules[orientation][rule];
}

ant_t*
move_forward(ant_t* ant, uint32_t width, uint32_t height) 
{
  #define ADJUST(p, v, limit) \
    do{                       \
      *(p) = (v) % (limit);   \
    } while(0)             
    
  switch(ant->o) { 
    case NORTH:
      ADJUST(&ant->y, ant->y - 1, height);
      break;
    case SOUTH:
      ADJUST(&ant->y, ant->y + 1, height);
      break;
    case EAST:
      ADJUST(&ant->x, ant->x + 1, width);
      break;
    case WEST:
      ADJUST(&ant->x, ant->x - 1, width);
      break;
    default:
      panic("Unknown orientation");
  }

  return ant;
}


void*
paint(void *artist_ant, void *grid, void *palette, void *rules,  uint32_t iterations)
{
  uint32_t i = 0;

  ant_t* ant = (ant_t*) artist_ant;

  const square_grid_t* sq_grid = (square_grid_t*) grid;
  const colour_t *colours = (colour_t*) palette;
  colour_t colour, next_colour;

  for (; i < iterations ; i ++) {
    /* Ant state */
    uint32_t current_x = ant->x;
    uint32_t current_y = ant->y;
    orientation_t current_o = ant->o;
    
    colour = sq_grid->grid[current_x][current_y];
    next_colour = colours[(i+1) % palette_len];

    /* Get rule for colour */
    rotation_t next_rotation = rule_for_colour(palette, rules, colour);

    /* 
    Now we need to update the ant's state 
    Rotate, then move forward.
    */
    ant->o = new_orientation(current_o, next_rotation);

    /* Paint with the next colour */
    sq_grid ->grid[current_x][current_y] = next_colour;

    ant = move_forward(ant, sq_grid->width, sq_grid->height);
  }
  panic ("Implement me!");
  return grid;
}

void*
make_rules(char *spec)
{
  const unsigned int l = strlen(spec);
  const unsigned int rule_len = l/2 + 1 ;

  rotation_t *rules = (rotation_t *) malloc(rule_len * sizeof(rotation_t));
  rotation_t each;

  rules_len = rule_len;
  for (unsigned int i = 0; i < l; i+=2) {
    if (spec[i] == 'L') {
      each = LEFT;
    }

    if (spec[i] == 'R') {
      each = RIGHT;
    }

    rules[i/2] = each;
  }

  return rules;
}

/**
 * Create a palette
 */
void*
make_palette(char *colour_spec)
{
  unsigned int i = 0;

  unsigned int l = strlen(colour_spec);

  const unsigned int colours = (l/2) + 1;
  colour_t *p = (colour_t *) malloc(colours * sizeof(colour_t));
  colour_t each;

  palette_len = colours;
  
  for(; i < l ; i+=2) {
    each = get_colour(colour_spec[i]);

    if (each < 0) {
      panic("Invalid colur")
    }

    p[i/2] = each;
  }

  
  
  return p;
}
#endif
