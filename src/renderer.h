#ifndef BC_RENDERER_H
#define BC_RENDERER_H

#include <stdint.h>

#include <SDL2/SDL_render.h>

#include "window.h"

typedef struct {
    uint8_t       created;
    SDL_Renderer *data;
} BcRenderer;

typedef struct {
    uint8_t      created;
    SDL_Texture *data;
} BcTexture;

void        bc_renderer_clear(BcRenderer *self);
void        bc_renderer_copy(BcRenderer *self, BcTexture *texture);
BcRenderer *bc_renderer_create(BcWindow* window);
void        bc_renderer_destroy(BcRenderer *self);
void        bc_renderer_present(BcRenderer *self);

BcTexture *bc_texture_create(BcRenderer *renderer, const char *path);
void       bc_texture_destroy(BcTexture *self);

#endif
