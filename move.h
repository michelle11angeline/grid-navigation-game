/*move.h - declare functions of move.c*/
#ifndef MOVE_H
#define MOVE_H
#include <stdbool.h> 

void move_player(char **grid, int grid_size, int *player_pos, int trap_pos[3], 
                int *lifelines, bool *key_found, int key_pos, char input);

#endif 