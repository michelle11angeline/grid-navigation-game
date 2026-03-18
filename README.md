# Grid Navigation Game (C)

This project is developed for Assignment one of the Unix and C Programming unit.  
The objective of this assignment is to design, implement, and test a grid-based navigation game using the C programming language and a 2D dynamic grid system.

In this game, the player navigates through a grid, collects keys, avoids traps, and manages limited lifelines to achieve the winning condition.

---

## Game Features
- Dynamic grid size (3x3 to 6x6)
- Player movement using:
  - `l` (left)
  - `r` (right)
  - `u` (up)
  - `d` (down)
- Randomly generated:
  - Key
  - Traps
- Lifeline system
- Win and lose conditions
- Input validation and error handling

---

## How to Compile and Run

### Compile
make

### Run 
This program is executed using the following format:
./navigateGrid <grid_size> <key_cell> <trap1_cell> <trap2_cell> <trap3_cell>

#### Parameter 
- grid_size (Defines the size of the grid (NxN), Must be between 3 and 6 (inclusive).)
- key_cell (Specifies the cell number containing the key (K).)
- trap1_cell, trap2_cell, trap3_cell (Specify the cell numbers containing traps (1, 2, 3), Stepping on a trap reduces one lifeline.)

#### Example 
./navigateGrid 4 10 2 6 8

## File Structure
- main.c : Program entry point and game loop
- game.c : Core game logic and conditions
- grid.c : Grid creation and memory management
- move.c : Player movement handling
- game.h : Game-related function declarations
- grid.h : Grid-related function declarations
- move.h : Movement-related function declarations
- Makefile : Compilation instructions

## Testing 
The program has been tested with:
- Minimum grid size (3x3)
- Maximum grid size (6x6)
- Boundary movement conditions
- Invalid user inputs
- Win and lose scenarios

## Notes
- The program uses dynamic memory allocation for grid creation.
- All allocated memory is properly freed to prevent memory leaks.
- Input validation is implemented to handle invalid or out-of-range inputs.
- The program has been tested using **Valgrind**, confirming:
  - No memory leaks
  - No invalid reads/writes
  - Safe memory usage throughout execution

## Author
Michelle Angeline 
Dploma of Information Technology 
Curtin University

