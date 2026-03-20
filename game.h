/*game.h - header file for macros, struct and function declaration of game.c*/
/*Guard to prevent multiple inclusion*/
#ifndef GAME_H
#define GAME_H

/*Macros that assign name to a value*/
#define FALSE 0
#define TRUE 1
#define TRAP_COUNT 3
#define MAX_GRID_SIZE 6
#define MIN_GRID_SIZE 3
#define CLEAR_SCREEN "\033[2J\033[H"

/*Structure that store and declare variable of Game State*/
typedef struct {
    int grid_size;
    int player_pos;
    int key_pos;
    int trap_pos[TRAP_COUNT];
    int lifelines;
    int key_found;
    char **grid;
} GameState;

/* Function Declaration*/
void startGame(int grid_size, const char *filename);
void generateRandomPositions(GameState *state);
void clear_screen(void);

#endif