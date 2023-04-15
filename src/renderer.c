#include "renderer.h"

#include <stdio.h>
#include <stdlib.h>

#include <SDL2/SDL_error.h>
#include <SDL2/SDL_image.h>

void bc_renderer_clear(BcRenderer *self)
{
    /* TODO: Add error handling */
    SDL_RenderClear(self->data);
}

void bc_renderer_copy(BcRenderer *self, BcTexture *texture)
{
    /* TODO: Add error handling */
    SDL_RenderCopy(self->data, texture->data, NULL, NULL);
}

BcRenderer *bc_renderer_create(BcWindow *window)
{
    BcRenderer *renderer = malloc(sizeof(BcRenderer));

    renderer->created = 1;
    renderer->data = SDL_CreateRenderer(window->data, -1, 0);
    if (renderer->data == NULL) {
        fprintf(stderr, "Failed to create renderer: %s\n", SDL_GetError());
        renderer->created = 0;
    }
    return renderer;
}

void bc_renderer_destroy(BcRenderer *self)
{
    if (self->data != NULL) {
        SDL_DestroyRenderer(self->data);
    }
    free(self);
}

void bc_renderer_present(BcRenderer *self)
{
    SDL_RenderPresent(self->data);
}

BcTexture *bc_texture_create(BcRenderer *renderer, const char *path)
{
    BcTexture *texture = malloc(sizeof(BcTexture));

    texture->created = 1;
    texture->data = IMG_LoadTexture(renderer->data, path);
    if (texture->data == NULL) {
        fprintf(stderr, "Failed to create texture: %s\n", IMG_GetError());
        texture->created = 0;
    }
    return texture;
}

void bc_texture_destroy(BcTexture *self)
{
    if (self->data != NULL) {
        SDL_DestroyTexture(self->data);
    }
    free(self);
}
