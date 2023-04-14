#ifndef BC_RENDERER_H
#define BC_RENDERER_H

#include <SDL2/SDL_render.h>

#include "window.h"

typedef struct {
    uint8_t       created;
    SDL_Renderer *data;
} BcRenderer;

void bc_renderer_clear(BcRenderer renderer);
void bc_renderer_copy(BcRenderer renderer, SDL_Texture *texture);
BcRenderer bc_renderer_create(BcWindow window);
void bc_renderer_destroy(BcRenderer renderer);
void bc_renderer_present(BcRenderer renderer);

#endif
