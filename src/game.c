#include "game.h"

#include <stdio.h>
#include <stdlib.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_image.h>

void bc_game_draw(BcAppState *state)
{
    bc_renderer_clear(state->renderer);
    bc_banana_draw(state->banana, state->renderer);
    bc_renderer_present(state->renderer);
}

void bc_game_initialize(BcAppState *state)
{
    int flags;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        fprintf(stderr, "Failed to initialize SDL: %s\n", SDL_GetError());
        exit(1);
    }

    flags = IMG_INIT_PNG;
    if (IMG_Init(flags) != flags) {
        fprintf(stderr, "Failed to initialize SDL image: %s\n", IMG_GetError());
        bc_game_quit(state);
        exit(1);
    }

    state->window = bc_window_create();
    if (!state->window->created) {
        bc_game_quit(state);
        exit(1);
    }

    state->renderer = bc_renderer_create(state->window);
    if (!state->renderer->created) {
        bc_game_quit(state);
        exit(1);
    }

    state->banana = bc_banana_create(state->renderer);
    if (!state->banana->created) {
        bc_game_quit(state);
        exit(1);
    }
}

void bc_game_quit(BcAppState *state)
{
    bc_window_destroy(state->window);
    bc_renderer_destroy(state->renderer);
    bc_banana_destroy(state->banana);

    SDL_Quit();
    IMG_Quit();
}

void bc_game_update(BcAppState *state)
{
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            state->running = 0;
        }
    }
    bc_banana_update(state->banana);
}
