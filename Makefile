CC=gcc
CFLAGS=-c -std=c11 -Werror -Wall -lm

all: game

game: main.o program.o ui.o
	$(CC) main.o program.o ui.o -o game -lncurses
	
main.o: main.c
	$(CC) $(CFLAGS) main.c

program.o: program.c
	$(CC) $(CFLAGS) program.c

ui.o: ui.c
	$(CC) $(CFLAGS) ui.c 

clean:
	rm -rf *.o game
