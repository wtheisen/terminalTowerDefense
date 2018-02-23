#ifndef tower_h
#define tower_h

#include "logging.h"

struct tower
{
    char type;
    int x, y;
    enum { NORTH, SOUTH, EAST, WEST} fireDir;
    int (*shoot)();
};
typedef struct tower tower;

int shoot(tower * self);
tower * newTower(int, int);

#endif
