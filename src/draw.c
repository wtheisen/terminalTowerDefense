#include "draw.h"
#include "engine.h"
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
            if (c == crumb2 || c == crumb1) c = path;
            mvaddch(i, j, c);
        }
    }

    mvprintw(1, SIZE + 2, "Killed: %d", enemiesKilled);
    mvprintw(3, SIZE + 2, "Reached: %d", enemiesReached);
    refresh();

    return 1;
}
