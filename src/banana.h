#ifndef BC_BANANA_H
#define BC_BANANA_H

#include "rect.h"
#include "renderer.h"
#include "types.h"

#define BANANA_STARTPOS_X 0
#define BANANA_STARTPOS_Y 0
#define BANANA_WIDTH 80
#define BANANA_HEIGHT 79

typedef struct {
    u8         created;
    BcRect     rect;
    BcTexture *texture;
} BcBanana;

BcBanana *bc_banana_create(BcRenderer *renderer);
void      bc_banana_destroy(BcBanana *self);
void      bc_banana_draw(BcBanana *self, BcRenderer *renderer);
void      bc_banana_update(BcBanana *self);

#endif
