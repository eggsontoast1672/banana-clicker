#include <stdio.h>
#include <stdint.h>

#include <SDL2/SDL.h>

#define BCLK_APP_TITLE "Banana Clicker"
#define BCLK_SCREEN_WIDTH 800
#define BCLK_SCREEN_HEIGHT 600

typedef struct {
    SDL_Window   *window;
    SDL_Renderer *renderer;
    uint8_t       running;
} BclkAppState;

static void bclk_initialize(BclkAppState *state);
static void bclk_quit(BclkAppState *state);
static void bclk_update(BclkAppState *state);

int main(void)
{
    BclkAppState state;

    state.running = 1;

    bclk_initialize(&state);

    while (state.running) {
        bclk_update(&state);
    }

    bclk_quit(&state);

    return 0;
}

static void bclk_initialize(BclkAppState *state)
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        fprintf(stderr, "Failed to initialize SDL: %s\n", SDL_GetError());
        exit(1);
    }
    state->window = SDL_CreateWindow(BCLK_APP_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, BCLK_SCREEN_WIDTH, BCLK_SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (state->window == NULL) {
        fprintf(stderr, "Failed to create window: %s\n", SDL_GetError());
        bclk_quit(state);
        exit(1);
    }
    state->renderer = SDL_CreateRenderer(state->window, -1, 0);
    if (state->renderer == NULL) {
        fprintf(stderr, "Failed to create renderer: %s\n", SDL_GetError());
        bclk_quit(state);
        exit(1);
    }
}

static void bclk_quit(BclkAppState *state)
{
    if (state->window) {
        SDL_DestroyWindow(state->window);
    }
    if (state->renderer) {
        SDL_DestroyRenderer(state->renderer);
    }
    SDL_Quit();
}

static void bclk_update(BclkAppState *state)
{
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            state->running = 0;
        }
    }
}
