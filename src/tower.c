#include "tower.h"

tower * newTower(int x, int y)
{
    tower * t = malloc(sizeof(*t));
    t->type = 1;
    t->fireDir = NORTH;
    t->x = x;
    t->y = y;
    t->shoot = shoot;

    return t;
}

int shoot(tower * self)
{
    int i;
    switch(self->fireDir)
    {
        case NORTH:
            writeLog("north");
            for (i = 1; i < 4; i++) {
                if (i < SIZE) {
                    projectileLayer[self->x - i][self->y] = 'b';
                }
            }
            break;
        case SOUTH:
            writeLog("south");
            for (i = 1; i < 4; i++) {
                if (i < SIZE) {
                    projectileLayer[self->x + i][self->y] = 'b';
                }
            }
            break;
        case EAST:
            writeLog("east");
            for (i = 1; i < 4; i++) {
                if (i < SIZE) {
                    projectileLayer[self->x][self->y - i] = 'b';
                }
            }
            break;
        case WEST:
            writeLog("west");
            for (i = 1; i < 4; i++) {
                if (i < SIZE) {
                    projectileLayer[self->x][self->y + i] = 'b';
                }
            }
            break;
    }

    return 0;
}
