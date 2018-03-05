#include <ncurses.h>
#include "draw.h"
#include "engine.h"
#include "levelGen.h"
#include "mouse.h"
#include "objectLayer.h"
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
                if (getHP(i, j) >= 4) {
                    attron(COLOR_PAIR(6));    
                }
                else if (getHP(i, j) == 3) {
                    attron(COLOR_PAIR(5));
                }
                else if (getHP(i, j) == 2) {
                    attron(COLOR_PAIR(4));
                } else if (getHP(i, j) == 1) {
                    attron(COLOR_PAIR(1));
                }
                if (projectileLayer[i][j] == 'b') {
                    writeLog("enemy - laser collision");
                    if (hitWalker(level, i, j)) {
                        attroff(COLOR_PAIR(1));
                        attron(COLOR_PAIR(3));
                        //enemy * e;
                        //e = objLayer[i][j];
                        mvaddch(i, j, getHP(i,j) + '0');
                    }
                } else {
                    //enemy * e;
                    //e = objLayer[i][j];
                    mvaddch(i, j, getHP(i, j) + '0');
                    //mvaddch(i, j, walker);
                }
                attroff(COLOR_PAIR(1));
                attroff(COLOR_PAIR(3));
            }else if (strchr("NESW", c) != NULL) {
                attron(COLOR_PAIR(2));
                switch(c)
                {
                    case 'N':
                        mvaddch(i, j, ACS_BTEE);
                        break;
                    case 'E':
                        mvaddch(i, j, ACS_LTEE);
                        break;
                    case 'S':
                        mvaddch(i, j, ACS_TTEE);
                        break;
                    case 'W':
                        mvaddch(i, j, ACS_RTEE);
                        break;
                }
                attroff(COLOR_PAIR(2));
            } else {
                if (projectileLayer[i][j] == 'b') {
                    attron(COLOR_PAIR(3));
                    mvaddch(i, j, ACS_BULLET);
                } else {
                    mvaddch(i, j, c);
                }
                attroff(COLOR_PAIR(3));
            }

        }
    }

    defProjLayer();

    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_CYAN, COLOR_BLACK);
    init_pair(3, COLOR_GREEN, COLOR_BLACK);
    
    if (currEnergy > 0 && enemiesKilled == 0) {
        mvprintw(1, SIZE +2, "Place %d more towers!", currEnergy / 5);
    } else {
    	attron(COLOR_PAIR(1));
            mvprintw(1, SIZE + 2, "Killed:  %d           ", enemiesKilled);
    	attroff(COLOR_PAIR(1));
    	attron(COLOR_PAIR(2));
            mvprintw(3, SIZE + 2, "Reached: %d", enemiesReached);
    	attroff(COLOR_PAIR(2));
            mvprintw(5, SIZE + 2, "               ");
    	attron(COLOR_PAIR(3));
            mvprintw(5, SIZE + 2, "Energy:  %d", currEnergy);
    	attroff(COLOR_PAIR(3));
    }

    mvprintw(SIZE + 1, SIZE / 3, "Enemies Remaining in Wave %d:  %d", currWave, enemiesRemaining);

    refresh();

    return 1;
}
