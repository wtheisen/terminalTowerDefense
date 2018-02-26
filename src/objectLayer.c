#include <stdlib.h>

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
    if (type == 1) {
        tower * t = o;
        objLayer[t->x][t->y] = t;
        writeLog("Added Tower to Object Layer");
    } else if (type == 2) {
        enemy * e = o;
        objLayer[e->x][e->y] = e;
        writeLog("Added Enemy to Object Layer");
    }
}

int activateObject(int type, int x, int y)
{
    char buffer[100];
    sprintf(buffer, "Activating object at %d,%d", x, y);
    writeLog(buffer);

    if (type == 1) {
        tower *t = objLayer[x][y];
        t->shoot(t);
    } else if (type == 2) {
        enemy *e = objLayer[x][y];
        return e->hit(e);
    }

    return 0;
}

void moveObject(int oldX, int oldY, int newX, int newY)
{
    objLayer[newX][newY] = objLayer[oldX][oldY];
    objLayer[oldX][oldY] = (void *) NULL;

    writeLog("Moved Enemy Object on Object Layer");
}

void deleteObject(int x, int y)
{
    
    free(objLayer[x][y]);
    
    objLayer[x][y] = (void *) NULL;
    writeLog("Removed Enemy Object from Object Layer");
}

void freeObjects() {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (objLayer[i][j] != NULL) free(objLayer[i][j]);
        }
    }
}


