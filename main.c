/*main.c - recieve user's input and start the game*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "game.h" 

/*main function to generate user's command line input*/
int main(int argc, char *argv[]) { 
    int grid_size;
    const char *output_file;
    if (argc != 3) { /*Check the input, if false print usage prompt and terminate*/
        printf("Usage: %s <grid_size> <file name>\n", argv[0]);
        return 1;
    }
    
    /*Parsing single number from user's command line input */
    grid_size= atoi(argv[1]); 
    output_file = argv[2];

    /*Check the input for the gridsize*/
    if (grid_size < MIN_GRID_SIZE || grid_size > MAX_GRID_SIZE) { 
        printf("Grid size must be between %d and %d.\n", MIN_GRID_SIZE, MAX_GRID_SIZE);
        return 1;
    }

    /*set the time to randomly generate number*/
    srand(time(NULL));

    /*initialize the game*/
    startGame(grid_size, output_file);
    return 0;
}
