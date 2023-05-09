#ifndef BC_WINDOW_H
#define BC_WINDOW_H

#include <SDL2/SDL_video.h>

#include "types.h"

#define BC_WINDOW_WIDTH 800
#define BC_WINDOW_HEIGHT 600

typedef struct {
    u8          created;
    SDL_Window *data;
} BcWindow;

BcWindow *bc_window_create(void);
void bc_window_destroy(BcWindow *window);

#endif
