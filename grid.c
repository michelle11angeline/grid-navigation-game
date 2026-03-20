/*grid.c - create and display grid*/
#include <stdio.h>
#include <stdlib.h>
#include "grid.h"

/*Create 2D char array with function pointer*/
char **create_grid(GameState *state) {
    int grid_size = state->grid_size;
    int i, j;

    /*Allocate memory of grid row pointer(coloum) on the heap*/
    char **grid = (char**)malloc(grid_size * sizeof(char *)); 
    if (grid == NULL) { 
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    
    /*Allocate memory for each row of array coloum*/
    for (i = 0; i < grid_size; i++) { 
        grid[i] = (char*)malloc(grid_size * sizeof(char));
        if (grid[i] == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            exit(EXIT_FAILURE);
        }
    }

    /*Initialize all cells as empty */
    for (i = 0; i < grid_size; i++) {
        for (j = 0; j < grid_size; j++) {
            grid[i][j] = ' ';
        }
    }

    /*Place key and traps */
    grid[state->key_pos / grid_size][state->key_pos % grid_size] = 'K';
    grid[state->trap_pos[0] / grid_size][state->trap_pos[0] % grid_size] = '1';
    grid[state->trap_pos[1] / grid_size][state->trap_pos[1] % grid_size] = '2';
    grid[state->trap_pos[2] / grid_size][state->trap_pos[2] % grid_size] = '3';
    return grid;
}
/*Display grid with previously created grid*/
void display_grid(GameState *state) {
    int i, j; 
    int grid_size = state->grid_size;
    int player_row = state->player_pos / grid_size;
    int player_col = state->player_pos % grid_size;

    printf("+");
    for (i = 0; i < grid_size; i++) {
        printf("---+");
    }
    printf("\n");

    /*Print grid contents */
    for (i = 0; i < grid_size; i++) {
        printf("|");
        for (j = 0; j < grid_size; j++) {
            if (i == player_row && j == player_col) {
                printf(" > |"); 
            }
            else if (state->grid[i][j] == 'K' && state->key_found) {
                printf(" %sK%s |", GREEN, RESET); /* Key in green */
            }
            else {
                printf(" %c |", state->grid[i][j]); 
            }
        }
        printf("\n+");
        for (j = 0; j < grid_size; j++) {
            printf("---+");
        }
        printf("\n");
    }
}

/*Free allocated memory to prevent memory leak*/
void free_grid(GameState *state) {
    int i; 
    
    for (i = 0; i < state->grid_size; i++) {
        free(state->grid[i]);
    }
    free(state->grid);
}
