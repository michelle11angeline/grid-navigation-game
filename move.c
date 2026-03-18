/*move.h - user's movement accordingly to input*/
#include <stdio.h> 
#include "move.h"

/*Function to move player according to user's input*/
void move_player(char **grid, int grid_size, int *player_pos, int trap_pos[3], 
                int *lifelines, bool *key_found, int key_pos, char input) {
    int new_pos = *player_pos; 
    int i;
    
    /*Handle user's input*/
    switch (input) {
        case 'u': /* Move up */
            if (*player_pos >= grid_size) {
                new_pos -= grid_size;
            }
            break;
        case 'l': /* Move left */
            if (*player_pos % grid_size != 0) {
                new_pos -= 1;
            }
            break;
        case 'd': /* Move down */
            if (*player_pos < grid_size * (grid_size - 1)) {
                new_pos += grid_size;
            }
            break;
        case 'r': /* Move right */
            if ((*player_pos + 1) % grid_size != 0) {
                new_pos += 1;
            }
            break;
        default:
            printf("Invalid input, enter again\n");
            return;
    }
    /* Check if new position has key */
    if (new_pos != *player_pos) {
        if (new_pos == key_pos) {
            *key_found = true;
        }
        
        /* Check if new position has trap */
        for (i = 0; i < 3; i++) {
            if (new_pos == trap_pos[i]) {
                (*lifelines)--;;
            }
        }

        /* Update player position */
        *player_pos = new_pos;
    }
}