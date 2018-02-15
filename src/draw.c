#include "draw.h"
#include "levelGen.h"

int drawGrid(char level[SIZE][SIZE])
{
    int mx, my;

    getmaxyx(stdscr, mx, my);

    int i = 0, j = 0;
    for (i = 0; i < SIZE; i++) {
        int it;
        for (it = 0; it < SIZE; it++) {
            char c = level[i][it];
            mvaddch(i, it, c);
        }
    }

    //for (j = 0; j < mx; j+=2) {
        //mvvline(0, j, '|', my);
    //}

    refresh();

    return 1;
}
