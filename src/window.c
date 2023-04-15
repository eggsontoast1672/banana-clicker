#include "window.h"

#include <stdio.h>
#include <stdlib.h>

#include <SDL2/SDL_error.h>

#include "game.h"

BcWindow *bc_window_create(void)
{
    BcWindow *window = malloc(sizeof(BcWindow));

    window->created = 1;
    window->data = SDL_CreateWindow(BC_GAME_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, BC_WINDOW_WIDTH, BC_WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    if (window->data == NULL) {
        fprintf(stderr, "Failed to create window: %s\n", SDL_GetError());
        window->created = 0;
    }
    return window;
}

void bc_window_destroy(BcWindow *window)
{
    if (window->data != NULL) {
        SDL_DestroyWindow(window->data);
    }
    free(window);
}
