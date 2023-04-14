#include "renderer.h"

void bc_renderer_clear(BcRenderer renderer)
{
    /* TODO: Add error handling */
    SDL_RenderClear(renderer.data);
}

void bc_renderer_copy(BcRenderer renderer, SDL_Texture *texture)
{
    /* TODO: Add error handling */
    SDL_RenderCopy(renderer.data, texture, NULL, NULL);
}

BcRenderer bc_renderer_create(BcWindow window)
{
    BcRenderer renderer;

    renderer.created = 1;
    renderer.data = SDL_CreateRenderer(window.data, -1, 0);
    if (renderer.data == NULL) {
        fprintf(stderr, "Failed to create renderer: %s\n", SDL_GetError());
        renderer.created = 0;
    }
    return renderer;
}

void bc_renderer_destroy(BcRenderer renderer)
{
    if (renderer.data != NULL) {
        SDL_DestroyRenderer(renderer.data);
    }
}

void bc_renderer_present(BcRenderer renderer)
{
    SDL_RenderPresent(renderer.data);
}
