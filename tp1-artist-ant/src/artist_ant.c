#include <stdio.h>
#include <getopt.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#include "ant_engine.h"
#include "artist_ant.h"
#include "builders.h"
#include "grid.h"
#include "palette.h"
#include "rules.h"

static ant_t ant;
static void* rules;

static int32_t iterations = 0 ;
static colour_t initial;

static void
show_warn(char *p)
{
     fprintf(stderr, " %s\n", p);
}

static void
show_help(char *p) {
    fprintf(stderr, "  %s -g <dimensions> -p <colors> -r <rules> -t <n>\n", p);
    fprintf(stderr, "  -g --grid: wxh\n");
    fprintf(stderr, "  -p --palette: Combination of R|G|B|Y|N|W\n");
    fprintf(stderr, "  -r --rules: Combination of L|R\n");
    fprintf(stderr, "  -n --times: Iterations\n");
    fprintf(stderr, "  -h --help: Print this message and exit\n");
    fprintf(stderr, "  -v --verbose: Version number\n");
}

static void
show_version()
{
  fprintf(stderr, "v0.0.0\n");
}

#define check_required(w, optarg)      \
  do {                                 \
    if (!(optarg)) {                   \
      show_warn((w));                  \
      show_help(argv[0]);              \
      exit(1);                         \
    }                                  \
  } while(0)

int
main(int argc, char **argv)
{
  static struct option long_options[] = {
    {"grid",  1, 0, 'g'},
    {"palette", 1, 0, 'p'},
    {"rules",  1, 0, 'r'},
    {"times",  1, 0, 't'},
    {"help", 0, 0, 'h'},
    {"version", 0, 0, 'v'},
    {0, 0, 0, 0}
  };
  static int long_index = 0;
  static char *rule_spec, *grid_spec, *colour_spec;
  
  unsigned int grid_width, grid_height, colour_spec_len, rule_spec_len;

  int opt, s, len = 0;
  char *dim_separator;

  ant_t *artist_ant;
  grid_handler_t *grid;

  colour_fn next_colour_fn;
  rule_fn rules;
  /* Parse arguments */
  while ((opt = getopt_long(argc, argv, "g:p:r:t:hv", long_options, &long_index)) != -1) {

    switch(opt) {
      case 'g': /* grid */
        dim_separator = strchr(optarg, 'x');
        assert(dim_separator != NULL);

        s = (unsigned int) (dim_separator - optarg);
        len = strlen(optarg);

        grid_width = atoui32(optarg, 0, s);
        grid_height = atoui32(optarg, s+1, len);

        break;
      case 'p': /* palette */
	      colour_spec_len = strlen(optarg);
        colour_spec = (char *) xmalloc(colour_spec_len);
        memcpy(colour_spec, optarg, strlen(optarg));
        initial = get_colour(optarg[0]);

        break;

      case 'r': /* rules */
       rule_spec_len = strlen(optarg);
       rule_spec = (char *) xmalloc(rule_spec_len);
       memcpy(rule_spec, optarg, rule_spec_len);

       break;

      case 't': /* times */
        iterations = atoi(optarg);

        if (iterations < 0){
          fprintf(stderr, "Must be non negative: %d",  iterations);
          show_help(argv[0]);
          exit(1);
        }
        break;

      case 'h': /* help */
        show_help(argv[0]);
        exit(0);
        break;

      case 'v': /* version */
        show_version();
        exit(0);
        break;

      default:
        fprintf(stderr, "Unrecognized option %c\n", opt );
        show_help(argv[0]);
        exit(1);
    }
  }

  /* Check arguments */
  check_required("Grid spec (h) is required", grid_height > 0);
  check_required("Grid spec (w) is required", grid_width > 0);
  check_required("Iterations is required", iterations > 0);

  check_required("Rule spec is required", rule_spec);
  check_required("Colour spec is required", colour_spec);

  check_required("Rule and colour length should match", strlen(rule_spec) == strlen(colour_spec));

  /* Get stuff in place */
  
  grid = make_grid(grid_width, grid_height, initial);
  next_colour_fn = make_palette(colour_spec, colour_spec_len);
  rules = make_rules(rule_spec, rule_spec_len, colour_spec, colour_spec_len);

  artist_ant = make_ant(grid_width >> 1, grid_height >> 1);
  
  /* Start the show */
  paint(artist_ant, grid, next_colour_fn, rules, iterations);

  grid_out(grid);

  return 0;
}

void*
make_ant(uint32_t xini, uint32_t yini)
{
  ant.x = xini;
  ant.y = yini;
  ant.o = NORTH;

  return &ant;
}

static void grid_out(grid_handler_t* grid)
{
  colour_t c;
  unsigned int grid_width = grid -> width;
  unsigned int grid_height = grid -> height;

  fprintf(stdout, "P3\n");
  fprintf(stdout, "%d %d\n", grid_width, grid_height);
  fprintf(stdout, "255\n");

  for (unsigned int i = 0;  i < grid_width; i++) {
    for (unsigned int j = 0;  j < grid_height; j++) {

      c = grid->get(i,j);

      switch(c) {
        case RED:
          printf("%d %-3d %-3d ", 255, 0, 0);
          break;
        case GREEN:
          printf("%-3d %d %-3d ", 0, 255, 0);
          break;
        case BLUE:
          printf("%-3d %-3d %d ", 0, 0, 255);
          break;
        case WHITE:
          printf("%d %d %d ", 255, 255, 255);
          break;
        case YELLOW:
          printf("%d %d %-3d ", 255, 255, 0);
          break;
        case BLACK:
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





