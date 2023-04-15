#include "game.h"

int main(void)
{
    /* TODO: Use atexit */

    BcAppState state;

    state.running = 1;

    bc_game_initialize(&state);

    while (state.running) {
        bc_game_update(&state);
        bc_game_draw(&state);
    }

    bc_game_quit(&state);

    return 0;
}

