/*grid.h - define macros and declare functions of grid.c*/
/*Guard to prevent multiple inclusion*/
#ifndef GRID_H
#define GRID_H

#include"game.h"
/*Macros that assign name to a value*/
#define GREEN "\033[0;32m"
#define RESET "\033[0m"

/* Function Declaration*/
char **create_grid(GameState *state);
void display_grid(GameState *state);
void free_grid(GameState *state);

#endif 