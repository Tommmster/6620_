#include <stdlib.h>

#include "palette.h"
#include "builders.h"

static colour_t *palette;
static size_t palette_len;

colour_fn
make_palette(const char *colour_spec, size_t palette_spec_len) 
{
  const size_t len_colours = spec_len(palette_spec_len);
  unsigned int i = 0;

  palette = (colour_t *) xmalloc(len_colours * sizeof(colour_t));
  palette_len = len_colours;

  colour_t each;

  for(; i < palette_spec_len ; i+=2) {
    each = get_colour(colour_spec[i]);

    if (COLOUR_NOT_FOUND == each) {
      panicd("Faulting colour spec %c", colour_spec[i]);
    }

    palette[i >> 1] = each;
  }
 
  return next_colour;
}

static colour_t
next_colour(void)
{
  static unsigned int current_index = 0;
	const unsigned int at = current_index++ % palette_len;

	return palette[at];
}

