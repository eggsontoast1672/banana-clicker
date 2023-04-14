#include <stdio.h>

#include <SDL2/SDL_image.h>

#include "renderer.h"

#define BC_FILE(filename) BC_SOURCE_DIR "/" filename

typedef struct {
    SDL_Texture *texture;
    BcWindow     window;
    BcRenderer   renderer;
    uint8_t      running;
} BcAppState;

static void bc_draw(BcAppState *state);
static void bc_initialize(BcAppState *state);
static void bc_quit(BcAppState *state);
static void bc_update(BcAppState *state);

int main(void)
{
    /* TODO: Use atexit */

    BcAppState state;

    state.running = 1;

#ifndef NDEBUG
    fprintf(stderr, "[DEBUG] BC_SOURCE_DIR = %s\n", BC_SOURCE_DIR);
    fprintf(stderr, "[DEBUG] BC_FILE(\"test\") = %s\n", BC_FILE("test"));
#endif

    bc_initialize(&state);

    while (state.running) {
        bc_update(&state);
        bc_draw(&state);
    }

    bc_quit(&state);

    return 0;
}

static void bc_draw(BcAppState *state)
{
    bc_renderer_clear(state->renderer);
    bc_renderer_copy(state->renderer, state->texture);
    bc_renderer_present(state->renderer);
}

static void bc_initialize(BcAppState *state)
{
    int flags;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        fprintf(stderr, "Failed to initialize SDL: %s\n", SDL_GetError());
        exit(1);
    }

    flags = IMG_INIT_PNG;
    if (IMG_Init(flags) != flags) {
        fprintf(stderr, "Failed to initialize SDL image: %s\n", IMG_GetError());
        bc_quit(state);
        exit(1);
    }

    state->window = bc_window_create();
    if (!state->window.created) {
        bc_quit(state);
        exit(1);
    }

    state->renderer = bc_renderer_create(state->window);
    if (!state->renderer.created) {
        bc_quit(state);
        exit(1);
    }

    state->texture = IMG_LoadTexture(state->renderer.data, BC_FILE("banana.png"));
    if (state->texture == NULL) {
        fprintf(stderr, "Failed to load texture: %s\n", IMG_GetError());
        bc_quit(state);
        exit(1);
    }
}

static void bc_quit(BcAppState *state)
{
    bc_window_destroy(state->window);
    if (state->texture) {
        SDL_DestroyTexture(state->texture);
    }
    SDL_Quit();
    IMG_Quit();
}

static void bc_update(BcAppState *state)
{
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            state->running = 0;
        }
    }
}
