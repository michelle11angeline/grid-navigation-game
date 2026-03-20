/*grid.h - define macros and declare functions of grid.c*/
#ifndef GRID_H
#define GRID_H

#include "game.h"

#define GREEN "\033[0;32m"
#define RESET "\033[0m"

char **create_grid(GameState *state);
void display_grid(GameState *state);
void free_grid(GameState *state);

#endif 