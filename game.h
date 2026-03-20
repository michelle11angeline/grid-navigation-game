/*game.h - declare game.c function declaration*/
#ifndef GAME_H
#define GAME_H

#define FALSE 0
#define TRUE 1
#define TRAP_COUNT 3
#define MAX_GRID_SIZE 6
#define MIN_GRID_SIZE 3
#define CLEAR_SCREEN "\033[2J\033[H"

typedef struct {
    int grid_size;
    int player_pos;
    int key_pos;
    int trap_pos[TRAP_COUNT];
    int lifelines;
    int key_found;
    char **grid;
} GameState;

void startGame(int grid_size, int key_cell, int trap1, int trap2, int trap3);
void clear_screen();

#endif 
