#include "draw.h"
#include "levelGen.h"

int drawGrid(char level[SIZE][SIZE])
{
    int mx, my;

    getmaxyx(stdscr, mx, my);

    int i = 0, j = 0;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            char c = level[i][j];
            mvaddch(i, j, c);
        }
    }

    //for (j = 0; j < mx; j+=2) {
        //mvvline(0, j, '|', my);
    //}

    refresh();

    return 1;
}
