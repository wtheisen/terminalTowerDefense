cc=gcc
binary=game
cflags=-O2 -Wextra -Wall -Iinclude/
src=src
libs=-lncurses

all:
	$(cc) $(src)/main.c -o $(binary) $(cflags) $(libs)

clean:
	rm $(binary)
	

