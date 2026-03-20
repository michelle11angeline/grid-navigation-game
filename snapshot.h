/*snapshot.h - header file that include game haeader to declare functio used in snapshot.c*/
/*Guard to prevent multiple inclusion*/
#ifndef GAMESTATE_H
#define GAMESTATE_H

/*Libraries for snapshot function*/
#include <stdio.h>  
#include "game.h"

/*Structure that declare variable of Grid State*/
typedef struct {
    char **grid;
    int size;
    int player_pos;
    int key_found;
} GridState;

/* Function Declaration*/
GridState* copyGameState(GameState *original);
void freeGridState(void *data);
void printGridState(void *data, FILE *file);

#endif
