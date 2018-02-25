#ifndef tower_h
#define tower_h

#include <stdlib.h>
#include <ncurses.h>

#include "logging.h"
#include "levelGen.h"

struct tower
{
    char type;
    int x, y;
    enum { NORTH, SOUTH, EAST, WEST} fireDir;
    int (*shoot)();
};
typedef struct tower tower;

extern char projectileLayer[SIZE][SIZE];

int shoot(tower * self);
tower * newTower(int, int);

#endif
