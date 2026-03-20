CC=gcc 
CFLAGS = -Wall -Wextra -Werror -pedantic -ansi
OBJ=main.o game.o move.o grid.o list.o snapshot.o
EXEC=navigateGrid  

navigateGrid: $(OBJ) 
	$(CC) $(OBJ) -o $(EXEC) 

main.o: main.c game.h
	$(CC) $(CFLAGS) main.c -c 

game.o: game.c game.h grid.h move.h list.h snapshot.h
	$(CC) $(CFLAGS) game.c -c

move.o: move.c move.h game.h
	$(CC) $(CFLAGS) move.c -c

grid.o: grid.c grid.h
	$(CC) $(CFLAGS) grid.c -c

list.o: list.c list.h
	$(CC) $(CFLAGS) list.c -c

snapshot.o: snapshot.c snapshot.h game.h 
	$(CC) $(CFLAGS) snapshot.c -c

clean: 
	rm -f $(OBJ) $(EXEC) 