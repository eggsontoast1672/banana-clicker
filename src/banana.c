#include "banana.h"

#include <stdlib.h>

#include "game.h"

BcBanana *bc_banana_create(BcRenderer *renderer)
{
    BcBanana *banana = malloc(sizeof(BcBanana));

    banana->rect.x = BANANA_STARTPOS_X;
    banana->rect.y = BANANA_STARTPOS_Y;
    banana->rect.w = BANANA_WIDTH;
    banana->rect.h = BANANA_HEIGHT;
    banana->texture = bc_texture_create(renderer, BC_FILE("banana.png"));

    return banana;
}

void bc_banana_destroy(BcBanana *self)
{
    bc_texture_destroy(self->texture);
    free(self);
}

void bc_banana_draw(BcBanana *self, BcRenderer *renderer)
{
    bc_renderer_copy(renderer, self->texture);
}
