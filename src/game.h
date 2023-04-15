#ifndef BC_GAME_H
#define BC_GAME_H

#include <stdint.h>

#include "banana.h"
#include "renderer.h"
#include "window.h"

#define BC_GAME_TITLE "Banana Clicker"

#define BC_FILE(filename) BC_SOURCE_DIR "/" filename

typedef struct {
    BcBanana   *banana;
    BcWindow   *window;
    BcRenderer *renderer;
    uint8_t     running;
} BcAppState;

void bc_game_draw(BcAppState *state);
void bc_game_initialize(BcAppState *state);
void bc_game_quit(BcAppState *state);
void bc_game_update(BcAppState *state);

#endif
