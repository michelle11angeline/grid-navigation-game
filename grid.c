/*grid.c - reate and display grid*/
#include <stdio.h>
#include <stdlib.h>
#include "grid.h"

/*Create 2D char array with function pointer*/
char **create_grid(int grid_size, int key_pos, int trap_pos[3]) {
    char **grid;
    int i, j; 
    
    /*Allocate memory of grid row pointer(coloum) on the heap*/
    grid = (char**)malloc(grid_size * sizeof(char *)); 
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
    grid[key_pos / grid_size][key_pos % grid_size] = 'K';
    grid[trap_pos[0] / grid_size][trap_pos[0] % grid_size] = '1';
    grid[trap_pos[1] / grid_size][trap_pos[1] % grid_size] = '2';
    grid[trap_pos[2] / grid_size][trap_pos[2] % grid_size] = '3';
    return grid;
}
/*Display grid with previously created grid*/
void display_grid(char **grid, int grid_size, int player_pos, bool key_found) {
    int i, j; 
    int player_row = player_pos / grid_size;
    int player_col = player_pos % grid_size;

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
            else if (grid[i][j] == 'K' && key_found) {
                printf(" %sK%s |", GREEN, RESET); /* Key in green */
            }
            else {
                printf(" %c |", grid[i][j]); 
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
void free_grid(char **grid, int grid_size) {
    int i; 
    
    for (i = 0; i < grid_size; i++) {
        free(grid[i]);
    }
    free(grid);
}