#ifndef __PALETTE_H__
#define __PALETTE_H__ 

#include "ant_types.h"

colour_fn make_palette(const char *, size_t);

static colour_t next_colour(void);
#endif /* __PALETTE_H__ */
