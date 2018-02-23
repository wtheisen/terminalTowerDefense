#include "objectLayer.h"
#include "logging.h"

void * objLayer[SIZE][SIZE];

void initObjectLayer()
{
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            objLayer[i][j] = (void *) NULL;
        }
    } 
}

void addObject(void * o, int type)
{
    if (type == 2) {
        enemy * e = o;
        objLayer[e->x][e->y] = e;
        writeLog("Added Enemy to Object Layer");
    }
}

void moveObject(int oldX, int oldY, int newX, int newY)
{
    objLayer[newX][newY] = objLayer[oldX][oldY];
    objLayer[oldX][oldY] = (void *) NULL;

    writeLog("Moved Enemy Object on Object Layer");
}


