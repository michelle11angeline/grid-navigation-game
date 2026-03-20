/*game.c - c file that store main game feature*/
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "game.h"
#include "grid.h"
#include "move.h"
#include "list.h"
#include "snapshot.h"

/*funtion to clear screen*/
void clear_screen(void) {
    printf(CLEAR_SCREEN);
}

void generateRandomPositions(GameState *state) {
    int grid_size = state->grid_size;
    int total_cells = grid_size * grid_size;
    int i, j;

    /*Random key position (not start or end)*/
    do {
        state->key_pos = rand() % total_cells;
    } while (state->key_pos == 0 || state->key_pos == total_cells - 1);

    /*Trap positions (not start, end, or key, and no duplicates)*/
    for (i = 0; i < TRAP_COUNT; i++) {
        int pos;
        int valid;
        do {
            valid = 1;
            pos = rand() % total_cells;

            if (pos == 0 || pos == total_cells - 1 || pos == state->key_pos) {
                valid = 0;
            } else {
                for (j = 0; j < i; j++) {
                    if (pos == state->trap_pos[j]) {
                        valid = 0;
                        break;
                    }
                }
            }
        } while (!valid);

        state->trap_pos[i] = pos;
    }
}

/*Function to run the game*/
void startGame(int grid_size, const char *filename) {
    /*Declaration of variable used in game loop*/
    int ch;
    char input;
    int valid_input;
    int game_over;
    LinkedList *history;
    GridState *stateCopy;
    GridState *finalCopy;

    /*Allocate struct variable to be used in function*/
    GameState *state = malloc(sizeof(GameState));
    if (!state) {
        fprintf(stderr, "Memory allocation failed for GameState\n");
        exit(EXIT_FAILURE);
    }

    /*Initializing and creating all variable for the game*/
    state->grid_size = grid_size;
    state->player_pos = 0;
    state->lifelines = 2;
    state->key_found = FALSE;
    generateRandomPositions(state);
    state->grid = create_grid(state);
    history = createList();

    /* Loop game until the condition is TRUE*/
    game_over = FALSE;
    while (!game_over) {
        clear_screen();
        display_grid(state);
        
        /* Save current state before every move to history */
        stateCopy = copyGameState(state);
        if (stateCopy) {
            insertFirst(history, stateCopy);
        }
        
        /* Ask user for the move*/
        printf("Lifelines: %d\n", state->lifelines);
        printf("Valid commands: (l)eft, (r)ight, (u)p, (d)own\n");

        /* Loop to check user's input, only move when valid */
        valid_input = FALSE;
        while (!valid_input) {
            printf("Where do you want to move? ");
            scanf(" %c", &input);

            while ((ch = getchar()) != '\n' && ch != EOF); 
            if (input == 'l' || input == 'r' || input == 'u' || input == 'd') {
                valid_input = TRUE;
                move_player(state, input);
            } else { 
                printf("Invalid input, enter again.\n");
            }
        }
        
        /* Check win/lose conditions */
        if (state->player_pos == grid_size * grid_size - 1 && state->key_found) {
            clear_screen();
            display_grid(state);
            printf("\nCongrast!! You Win the game!\n\n");
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
    /*Save the final move to history */
    finalCopy = copyGameState(state);
    if (finalCopy) {
        insertFirst(history, finalCopy);
    }

    /* Save history to file before exiting */
    saveToFileReverse(history, filename, printGridState);
    /* To free all the allocated memory*/
    freeList(history, freeGridState);
    free_grid(state);
    free(state);
}
