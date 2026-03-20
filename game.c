#include <stdlib.h>
#include <stdio.h>
#include "game.h"
#include "grid.h"
#include "move.h"

void clear_screen(void) {
    printf(CLEAR_SCREEN);
}

void generateRandomPositions(GameState *state) {
    int grid_size = state->grid_size;
    int total_cells = grid_size * grid_size;
    int i, j;

    do {
        state->key_pos = rand() % total_cells;
    } while (state->key_pos == 0 || state->key_pos == total_cells - 1);

    for (i = 0; i < TRAP_COUNT; i++) {
        int pos;
        int valid;

        do {
            valid = TRUE;
            pos = rand() % total_cells;

            if (pos == 0 || pos == total_cells - 1 || pos == state->key_pos) {
                valid = FALSE;
            } else {
                for (j = 0; j < i; j++) {
                    if (pos == state->trap_pos[j]) {
                        valid = FALSE;
                        break;
                    }
                }
            }
        } while (!valid);

        state->trap_pos[i] = pos;
    }
}

void startGame(int grid_size, const char *filename) {
    GameState *state = malloc(sizeof(GameState));
    if (!state) {
        fprintf(stderr, "Memory allocation failed for GameState\n");
        exit(EXIT_FAILURE);
    }

    state->grid_size = grid_size;
    state->player_pos = 0;
    state->lifelines = 2;
    state->key_found = FALSE;

    generateRandomPositions(state);
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

    (void)filename;
    free_grid(state);
    free(state);
}