#include <stdlib.h>

#include "enemy.h"

/*int shoot(enemy * self)
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
}*/

enemy * newEnemy(int x, int y) 
{
    enemy * e = malloc(sizeof(*e));
    e->type = 2; 
    e->x = x;
    e->y = y;
    e->hp = 5;
    
    return e; 
}