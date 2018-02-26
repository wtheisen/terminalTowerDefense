#include "draw.h"
#include "engine.h"
#include "levelGen.h"
#include "mouse.h"
#include "symbols.h"
#include "logging.h"


int drawGrid(char level[SIZE][SIZE])
{

    int i = 0, j = 0;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            char c = level[i][j];
            if (c == crumb2 || c == crumb1) c = path;
            if (c == walker) {
                if (projectileLayer[i][j] == 'b') {
                    attron(COLOR_PAIR(2));
                    writeLog("enemy - laser collision");
                    if (hitWalker(level, i, j)) {
                        c = level[i][j];
                        mvaddch(i, j, c);
                    }
                    attroff(COLOR_PAIR(2));
                } else {
                    mvaddch(i, j, walker);
                }
            } else {
                if (projectileLayer[i][j] == 'b') {
                    c = laser;
                }
                mvaddch(i, j, c);
            } 
            
            /*}else if (c == shooter) {
                attron(COLOR_PAIR(2));
                mvaddch(i, j, c);
                attroff(COLOR_PAIR(2));
            } else {
                mvaddch(i, j, c);
            } */
            
        }
    }

    defProjLayer();

    if (towersRemaining > 0) {
        mvprintw(1, SIZE +2, "Place %d more towers!", towersRemaining);
    } else {
        mvprintw(1, SIZE + 2, "Killed: %d           ", enemiesKilled);
        mvprintw(3, SIZE + 2, "Reached: %d", enemiesReached);
    }
    refresh();

    return 1;
}
