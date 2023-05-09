#include "banana.h"

#include <stdlib.h>

#include "game.h"
#include "window.h"

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
    bc_renderer_copy(renderer, self->texture, self->rect);
}

void bc_banana_update(BcBanana *self)
{
    self->rect.x += 1;
    self->rect.y += 1;

    if (self->rect.x < 0) {
        self->rect.x = 0;
    } else if (self->rect.x + self->rect.w > BC_WINDOW_WIDTH) {
        self->rect.x = BC_WINDOW_WIDTH - self->rect.w;
    }

    if (self->rect.y < 0) {
        self->rect.y = 0;
    } else if (self->rect.y + self->rect.h > BC_WINDOW_HEIGHT) {
        self->rect.y = BC_WINDOW_HEIGHT - self->rect.h;
    }
}
