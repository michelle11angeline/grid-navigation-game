#include <stdio.h>
#include <stdlib.h>
#include "grid.h"

int main(void) {
    int size = 5;

    char **grid = createGrid(size);
    if (grid == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printGrid(grid, size);

    freeGrid(grid, size);
    return 0;
}