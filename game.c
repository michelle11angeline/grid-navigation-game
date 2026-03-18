/*game.c - game feature*/
#include <stdlib.h>
#include <stdio.h>
#include "game.h"
#include "grid.h"
#include "move.h"

/*funtion to clear screen*/
void clear_screen() {
    printf(CLEAR_SCREEN);
}

/*game function*/
void startGame(int grid_size, int key_cell, int trap1, int trap2, int trap3) {
    int key_pos = key_cell - 1;
    int trap_pos[3] = {trap1 - 1, trap2 - 1, trap3 - 1};
    int player_pos = 0; 
    int lifelines = 2;
    bool key_found = false;
    
    /*Create grid*/
    char **grid = create_grid(grid_size, key_pos, trap_pos);
    
    char input;
    bool game_over = false;

    /*Play until win or lose condition*/
    while (!game_over) {
        clear_screen();
        display_grid(grid, grid_size, player_pos, key_found);
        
        printf("Lifelines: %d\n", lifelines);
        printf("Where do you want to move? (l)eft, (r)ight, (u)p, (d)own: ");
        scanf(" %c", &input);

        move_player(grid, grid_size, &player_pos, trap_pos, &lifelines, &key_found, key_pos, input);
        
        /*Check win condition (at exit with key)*/
        if (player_pos == grid_size * grid_size - 1 && key_found) {
            clear_screen();
            display_grid(grid, grid_size, player_pos, key_found);
            printf("\nYou Win the game!\n");
            game_over = true;
        }
        /*Check lose conditions*/
        else if (lifelines <= 0) {
            clear_screen();
            display_grid(grid, grid_size, player_pos, key_found);
            printf("\nYou Lost the game! No lifelines left.\n");
            game_over = true;
        }
        else if (player_pos == grid_size * grid_size - 1 && !key_found) {
            clear_screen();
            display_grid(grid, grid_size, player_pos, key_found);
            printf("\nYou Lost the game! Exit reached without key.\n");
            game_over = true;
        }
    }

    free_grid(grid, grid_size);
}