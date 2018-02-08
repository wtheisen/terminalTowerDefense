cc=gcc
binary=game
cflags=-O2 -Wextra -Wall
libs=-lncurses

all:
	$(cc) test.c -o $(binary) $(cflags) $(libs)

clean:
	rm $(binary)
	

