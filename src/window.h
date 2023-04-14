#ifndef BC_WINDOW_H
#define BC_WINDOW_H

#include <bits/stdint-uintn.h>

#include <SDL2/SDL_video.h>

#define BC_WINDOW_WIDTH 800
#define BC_WINDOW_HEIGHT 600

typedef struct {
    uint8_t     created;
    SDL_Window *data;
} BcWindow;

BcWindow bc_window_create(void);
void bc_window_destroy(BcWindow window);

#endif
