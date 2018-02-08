binary=game
cc=gcc
cflags=-O2 -Wextra -Wall -Iinclude/
main=main.c
libs=-lncurses
src=src

all: 
	$(cc) $(src)/* -o $(binary) $(cflags) $(libs)

clean:
	rm $(binary)
	

