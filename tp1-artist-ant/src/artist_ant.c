#include <stdio.h>
#include <getopt.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "artist_ant.h"


static uint32_t grid_width;
static uint32_t grid_height;
static square_grid_t grid;

static ant_t ant;
static palette_t palette;

static uint32_t w, h, n;
static char initial;

void show_version();

void show_help(char *);

/*
* Dimensiones de la grilla (w x h)
* Paleta de colores (R|G|B|W|Y)
* Reglas (L|R ..)
* Número de iteraciones (entero positivo)
*/
int
main(int argc, char **argv)
{
  ant_t *artist_ant;
  square_grid_t *square_grid;
  palette_t *colours;
  static struct option long_options[] = {
    {"grid",  1, 0, 'g'},
    {"palette", 1, 0, 'p'},
    {"rules",  1, 0, 'r'},
    {"iterations",  1, 0, 'n'},
    {"help", 0, 0, 'h'},
    {"version", 0, 0, 'v'},
    {0, 0, 0, 0}
  };
  static char *rule_spec, *grid_spec;

  int opt, s, len = 0;
  int long_index = 0;

  while ((opt = getopt_long(argc, argv, "g:p:r:n:hv", long_options, &long_index)) != -1) {

    switch(opt) {
      case 'g':
        len = strlen(optarg);
        s = (unsigned int) (strchr(optarg, 'x') - optarg);

        grid_width = as_int(optarg, 0, s);
        grid_height = as_int(optarg, s+1, len);

        break;
      case 'p':
        colours = make_palette((unsigned char *)optarg);
        initial = optarg[0];

        break;

      case 'r':
        memcpy(rule_spec, optarg, strlen(optarg));
        break;

      case 'n':
        n = atoi(optarg);
        break;

      case 'h':
        show_help(argv[0]);
        exit(0);
        break;

      case 'v':
        show_version();
        exit(0);
        break;

      default:
        exit(1);
    }
  }

  printf("Grid %dx%d\n", grid_width, grid_height);
  printf("Initial colour %c\n", initial);

  printf("Rules %s\n",rule_spec);

  square_grid = make_grid(grid_width, grid_height, initial);
  artist_ant = make_ant(w/2, h/2);

  paint(artist_ant, square_grid, colours, rule_spec, n);

  grid_out();

  return 0;
}

void*
paint(void *ant, void *grid, void *palette, void *rules,  uint32_t iterations)
{
  return grid;
}

void*
make_grid(uint32_t w, uint32_t h, uint32_t c)
{
  grid.width = w;
  grid.height = h;

  grid.grid = (uint32_t **) malloc( w * sizeof(uint32_t*));

  for (int i=0; i < w; i++){
    grid.grid[i] = (uint32_t *) malloc ( h * sizeof(uint32_t));
    for (int j = 0; j < h; j++) {
      memset(&grid.grid[i][j], c, sizeof(uint32_t));
    }
  }

  return &grid;
}

void*
make_palette(unsigned char *colours)
{
  return NULL;
}

void*
make_ant(uint32_t xini, uint32_t yini)
{
  ant.x = xini;
  ant.y = yini;
  ant.o = NORTH;

  return &ant;
}

void grid_out()
{
  char c;
  printf("P3\n");
  printf("%d %d\n", grid_width, grid_height);
  printf("255\n");

  for (unsigned int i = 0;  i < grid_width; i++) {
    for (unsigned int j = 0;  j < grid_height; j++) {

      c = grid.grid[i][j];

      switch(c) {
        case 'R':
          printf("%d %-3d %-3d ", 255, 0, 0);
          break;
        case 'G':
          printf("%-3d %d %-3d ", 0, 255, 0);
          break;
        case 'B':
          printf("%-3d %-3d %d ", 0, 0, 255);
          break;
        case 'W':
          printf("%d %d %d ", 255, 255, 255);
          break;
        case 'Y':
          printf("%d %d %-3d ", 255, 255, 0);
          break;
        case 'N':
          printf("%-3d %-3d %-3d ", 0, 0, 0);
          break;
        default:
          fprintf(stderr, "Invalid: %c\n", c);
          exit(2);
      }
    }
    printf("\n");
  }
}

uint32_t
as_int(void *arg, uint32_t from, uint32_t to)
{

  assert(from < to);

  const unsigned char *s = (unsigned char *) arg + from;
  unsigned char *t = (unsigned char *)(arg + to);

  uint32_t n = 0;

  while (s < t) {
    n = (*s - '0') + n * 10;
    s ++;
  }

  return n;
}

void
show_help(char *p) {
    printf("%s -g <dimensions> -p <colors> -r <rules> -t <n>\n", p);
    printf("-g --grid: wxh\n");
    printf("-p --palette: Combination of R|G|B|Y|N|W\n");
    printf("-r --rules: Combination of L|R\n");
    printf("-n --times: Iterations\n");
    printf("-h --help: Print this message and exit\n");
    printf("-v --verbose: Version number\n");
}

void
show_version()
{
  printf("v0.0.0\n");
}

