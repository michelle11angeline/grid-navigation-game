#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "game.h"

int main(int argc, char *argv[]) { 
    int grid_size;
    const char *output_file;

    if (argc != 3) {
        printf("Usage: %s <grid_size> <file name>\n", argv[0]);
        return 1;
    }
    
    grid_size = atoi(argv[1]);
    output_file = argv[2];

    if (grid_size < MIN_GRID_SIZE || grid_size > MAX_GRID_SIZE) {
        printf("Grid size must be between %d and %d.\n", MIN_GRID_SIZE, MAX_GRID_SIZE);
        return 1;
    }

    srand(time(NULL));

    startGame(grid_size, output_file);
    return 0;
}