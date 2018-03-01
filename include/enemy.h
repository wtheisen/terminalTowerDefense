#ifndef enemy_h
#define enemy_h

#include "logging.h"
#include "objectLayer.h"

struct enemy
{
    char type;
    int x, y;
    int hp;
    int (*hit)();
};
typedef struct enemy enemy;

enemy * newEnemy(int, int, int);
int hit(enemy * self);

//int shoot(enemy * self);

#endif
