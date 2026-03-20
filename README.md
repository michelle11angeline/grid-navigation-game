# Grid Navigation Game (C)

This project is developed for Assignment 1 (improved acccording to assignment 2) of the Unix and C Programming unit.  
The objective of this assignment is to design, implement, and test a grid-based navigation game using the C programming language and a 2D dynamic grid system.

In this game, the player navigates through a grid, collects a key, avoids traps, and manages limited lifelines to achieve the winning condition.  
Additionally, the program records the entire gameplay history and saves it to an output file. 

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

### New Features (Assignment 2)

- Generic linked list implementation
- Snapshot system to store game states
- Deep copy of grid at every move
- Game history recorded throughout gameplay
- Output file generation with all grid states
- History saved in reverse order (last move first)

---

## How to Compile and Run

### Compile
make

### Run 
This program is executed using the following format:
./game <grid_size> <output_file>

#### Parameter 
- grid_size (Defines the size of the grid (NxN), Must be between 3 and 6 (inclusive).)
- output_file (Name of the file where game history will be saved)

#### Example 
./game 5 output.txt

## Output File
- The program generates an output file containing all game states
- Each move is recorded as a snapshot
- The history is saved in reverse order
- Each snapshot displays: Grid layout and Player position

## File Structure
- main.c → Program entry point and input handling
- game.c → Core game logic and game loop
- grid.c → Grid creation and memory management
- move.c → Player movement handling
- list.c → Generic linked list implementation
- snapshot.c → Snapshot creation, printing, and memory management
- *.h → Header files for modular structure
- Makefile → Compilation instructions

## Testing 
The program has been tested with:
- Minimum grid size (3x3)
- Maximum grid size (6x6)
- Boundary movement conditions
- Invalid user inputs
- Win and lose scenarios
- File output correctness

## Notes
- The program uses dynamic memory allocation
- All allocated memory is properly freed
- Linked list nodes and snapshots are deallocated correctly
- The program has been tested using **Valgrind**, confirming:
  - No memory leaks
  - No invalid reads/writes
  - Safe memory usage throughout execution

## Author
Michelle Angeline 
Dploma of Information Technology 
Curtin University
