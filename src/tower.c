#include <stdlib.h>

#include "tower.h"

tower * newTower(int x, int y)
{
    tower * t = malloc(sizeof(*t));
    t->type = 1;
    t->x = x;
    t->y = y;
    
    return t;
}

int shoot(tower * self)
{
    //x is the direction, as is y. 0,0 is assumed the be the bottom right corner

    switch(self->fireDir)
    {
        case NORTH:
            writeLog("north");
            break;
        case SOUTH:
            writeLog("south");
            break;
        case EAST:
            writeLog("east");
            break;
        case WEST:
            writeLog("west");
            break;
    }

    return 0;
}
