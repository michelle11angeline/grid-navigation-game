/*main.c - recieve user's input and start the game*/
#include <stdio.h>
#include <stdlib.h>
#include "game.h" 

/*main function to generate user's command line input*/
int main(int argc, char *argv[]) { 
    if (argc != 6) { /*Check the input, if false print usage prompt and terminate*/
        printf("Usage: %s <grid_size> <key_cell> <trap1> <trap2> <trap3>\n", argv[0]);
        return 1;
    }
    
    /*Parsing single number from user's command line input */
    int grid_size = atoi(argv[1]); 
    int key_cell = atoi(argv[2]); 
    int trap1 = atoi(argv[3]); 
    int trap2 = atoi(argv[4]);
    int trap3 = atoi(argv[5]);

    /*Check the input for the gridsize*/
    if (grid_size < 3 || grid_size > 6) { 
        printf("Grid size must be between 3 and 6.\n");
        return 1;
    }

    /*initialize the game*/
    startGame(grid_size, key_cell, trap1, trap2, trap3);
    return 0;
}
