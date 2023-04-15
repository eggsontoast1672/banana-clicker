#ifndef BC_BANANA_H
#define BC_BANANA_H

#include <stdint.h>

#include <SDL2/SDL_rect.h>

#include "renderer.h"

#define BANANA_STARTPOS_X 0
#define BANANA_STARTPOS_Y 0
#define BANANA_WIDTH 100
#define BANANA_HEIGHT 100

typedef struct {
    uint8_t    created;
    SDL_Rect   rect;
    BcTexture *texture;
} BcBanana;

BcBanana *bc_banana_create(BcRenderer *renderer);
void      bc_banana_destroy(BcBanana *self);
void      bc_banana_draw(BcBanana *self, BcRenderer *renderer);

#endif
