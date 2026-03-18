/*grid.h - define macros and declare functions of grid.c*/
#ifndef GRID_H
#define GRID_H
#include <stdbool.h> 

#define CLEAR_SCREEN "\033[2J\033[H"
#define GREEN "\033[0;32m"
#define RESET "\033[0m"

char **create_grid(int grid_size, int key_pos, int trap_pos[3]);
void display_grid(char **grid, int grid_size, int player_pos, bool key_found);
void free_grid(char **grid, int grid_size);

#endif 