/*snapshot.c - copy, free and print game grid & state*/
#include <stdlib.h>
#include "snapshot.h"
#include "game.h"

/* Create a deep copy of the game state */
GridState* copyGameState(GameState *original) {
    int i, j;
    /*Allocate struct variable to be used in function*/
    GridState *copy = malloc(sizeof(GridState));
    if (!copy) return NULL;
    
    /*Copy the current grid state from Gamestate */
    copy->size = original->grid_size;
    copy->player_pos = original->player_pos;
    copy->key_found = original->key_found;
    
    /* Allocate memory for full grid copy */
    copy->grid = malloc(copy->size * sizeof(char*));
    if (!copy->grid) {
        free(copy);
        return NULL;
    }
    
    /*Copy grid*/
    for (i = 0; i < copy->size; i++) {
        copy->grid[i] = malloc(copy->size * sizeof(char));
        if (!copy->grid[i]) {
            for (j = 0; j < i; j++) free(copy->grid[j]);
            free(copy->grid);
            free(copy);
            return NULL;
        }
        for (j = 0; j < copy->size; j++) {
            copy->grid[i][j] = original->grid[i][j];
        }
    }
    return copy;
}

/* Function to print GridState to file */
void printGridState(void *data, FILE *file) { 
    /*Allocate struct variable to be used in function*/
    GridState *state = (GridState *)data; 

    /*Variable initialization and declaration*/
    int i, j; 
    int grid_size = state->size;
    int player_row = state->player_pos / grid_size;
    int player_col = state->player_pos % grid_size;

    /*Print the grid into file*/
    fprintf(file, "+");
    for (i = 0; i < grid_size; i++) {
        fprintf(file, "---+");
    }
    fprintf(file, "\n");

    for (i = 0; i < grid_size; i++) {
        fprintf(file, "|");
        for (j = 0; j < grid_size; j++) {
            if (i == player_row && j == player_col) {
                fprintf(file, " > |");  
            } else {
                fprintf(file, " %c |", state->grid[i][j]);
            }
        }
        fprintf(file, "\n+");
        for (j = 0; j < grid_size; j++) {
            fprintf(file, "---+");
        }
        fprintf(file, "\n");
    }
}

/* Function to free a GridState */
void freeGridState(void *data) {
    /*Allocate struct variable to be used in function*/
    GridState *state = (GridState*)data;
    /*Free all grid from the start to null*/
    if (state) {
        int i;
        for (i = 0; i < state->size; i++) {
            free(state->grid[i]);
        }
        free(state->grid);
        free(state);
    }
}
