#include "draw.h"
#include "levelGen.h"
#include "symbols.h"

int drawGrid(char level[SIZE][SIZE])
{
    //int mx, my;
    //getmaxyx(stdscr, mx, my);

    int i = 0, j = 0;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            char c = level[i][j];
            if (c == placeholder2 || c == placeholder1) c = path;
            mvaddch(i, j, c);
        }
    }


    refresh();

    return 1;
}
