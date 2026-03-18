CC=gcc 
CFLAGS=-Wall -ansi 
OBJ=main.o game.o move.o grid.o 
EXEC=navigateGrid  

navigateGrid: $(OBJ) 
	$(CC) $(OBJ) -o $(EXEC) 

main.o: main.c game.h
	$(CC) $(CFLAGS) main.c -c 

game.o: game.c game.h grid.h move.h
	$(CC) $(CFLAGS) game.c -c

move.o: move.c move.h 
	$(CC) $(CFLAGS) move.c -c

grid.o: grid.c grid.h
	$(CC) $(CFLAGS) grid.c -c

clean: 
	rm -f $(OBJ) $(EXEC) 
