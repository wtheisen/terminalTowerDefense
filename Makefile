binary=game
cc=gcc
cflags= -std=c99 -O2 -Wextra -Wall -Iinclude/ -g
main=main.c
libs=-lncurses
src=src

all:
	$(cc) $(src)/* -o $(binary) $(cflags) $(libs)

debug: all
	valgrind --log-file="valgrind.log" ./$(binary)

clean:
	rm -f $(binary)


