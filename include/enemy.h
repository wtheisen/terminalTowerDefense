#ifndef enemy_h
#define enemy_h

#include "logging.h"

struct enemy
{
    char type;
    int x, y;
    int hp;
    //int (*shoot)();
};

typedef struct enemy enemy;

enemy newEnemy(int, int);

//int shoot(enemy * self);

#endif
