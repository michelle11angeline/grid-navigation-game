/*move.h - user's movement accordingly to input*/
#include <stdio.h> 
#include "move.h"
#include "game.h"

/*Function to move player according to user's input*/
void move_player(GameState *state, char input) {
    int new_pos = state->player_pos; 
    int grid_size = state->grid_size;
    int i;
    
    /*Handle user's input*/
    switch (input) {
        case 'u': /* Move up */
            if (new_pos >= grid_size) {
                new_pos -= grid_size;
            }
            break;
        case 'l': /* Move left */
            if (new_pos % grid_size != 0) {
                new_pos -= 1;
            }
            break;
        case 'd': /* Move down */
            if (new_pos < grid_size * (grid_size - 1)) {
                new_pos += grid_size;
            }
            break;
        case 'r': /* Move right */
            if ((new_pos + 1) % grid_size != 0) {
                new_pos += 1;
            }
            break;
        default:
            return;
    }
    /* Check if new position has key */
    if (new_pos != state->player_pos) {
        if (new_pos == state->key_pos) {
            state->key_found = TRUE;
        }
        
        /* Check if new position has trap */
        for (i = 0; i < TRAP_COUNT; i++) {
            if (new_pos == state->trap_pos[i]) {
                state->lifelines--;
            }
        }

        /* Update player position */
        state->player_pos = new_pos;
    }
}