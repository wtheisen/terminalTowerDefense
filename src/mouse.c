#include "ncurses.h"

#include "draw.h"
#include "logging.h"
#include "mouse.h"
#include "objectLayer.h"
#include "symbols.h"
#include "tower.h"

int towersRemaining = 5;
extern WINDOW * win;

void addTowers(char level[SIZE][SIZE]) {
    drawGrid(level);

    mousemask(ALL_MOUSE_EVENTS, NULL);
    keypad(win, TRUE); 
    
    char buffer[100];

    MEVENT event; 

    while (towersRemaining > 0) {
        int c = wgetch(win);
        switch(c) {
            case KEY_MOUSE:
                if (getmouse(&event) == OK) {
                    if (event.bstate & BUTTON1_CLICKED) {
                        
                        if (event.x >= SIZE || event.y >= SIZE) continue;

                        sprintf(buffer, "Mouse clicked at %d,%d", event.y, event.x);
                        writeLog(buffer);                        

                        if (level[event.y][event.x] != weeds) continue;
                        
                        tower * t = newTower(event.y, event.x);
                        sprintf(buffer, "%p", t);
                        writeLog(buffer);
                        addObject((void *) t, t->type);
                        
                        level[event.y][event.x] = shooter;
                        towersRemaining--;
                        
                    } else {
                        writeLog("Unknown Mousepress");
                    }
                } else {
                    writeLog("Broken Mousepress");
                }
                break;
            default: 
                break;
        }
        drawGrid(level);
        refresh();
    }
}
