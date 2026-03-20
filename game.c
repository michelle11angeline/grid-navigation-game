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
    GameState *state = malloc(sizeof(GameState));
    if (!state) {
        fprintf(stderr, "Memory allocation failed for GameState\n");
        exit(EXIT_FAILURE);
    }

    state->grid_size = grid_size;
    state->player_pos = 0;
    state->key_pos = key_cell - 1;
    state->trap_pos[0] = trap1 - 1;
    state->trap_pos[1] = trap2 - 1;
    state->trap_pos[2] = trap3 - 1;
    state->lifelines = 2;
    state->key_found = FALSE;
    state->grid = create_grid(state);

    {
        char input;
        int game_over = FALSE;

        while (!game_over) {
            clear_screen();
            display_grid(state);

            printf("Lifelines: %d\n", state->lifelines);
            printf("Where do you want to move? (l)eft, (r)ight, (u)p, (d)own: ");
            scanf(" %c", &input);

            move_player(state, input);

            if (state->player_pos == grid_size * grid_size - 1 && state->key_found) {
                clear_screen();
                display_grid(state);
                printf("\nYou Win the game!\n");
                game_over = TRUE;
            }
            else if (state->lifelines <= 0) {
                clear_screen();
                display_grid(state);
                printf("\nYou Lost the game! No lifelines left.\n");
                game_over = TRUE;
            }
            else if (state->player_pos == grid_size * grid_size - 1 && !state->key_found) {
                clear_screen();
                display_grid(state);
                printf("\nYou Lost the game! Exit reached without key.\n");
                game_over = TRUE;
            }
        }
    }

    free_grid(state);
    free(state);
}