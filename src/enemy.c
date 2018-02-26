#include <stdlib.h>

#include "enemy.h"

enemy * newEnemy(int x, int y)
{
    enemy * e = malloc(sizeof(*e));
    e->type = 2;
    e->x = x;
    e->y = y;
    e->hp = 1;
    e->hit = hit;

    return e;
}

int hit(enemy * self)
{
    writeLog("Hit called");

    self->hp--;

    if (self->hp <= 0) {
        deleteObject(self->x, self->y);
        return 1;
    }

    return 0;
}
