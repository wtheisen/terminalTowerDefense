#include "enemy.h"
#include "engine.h"
#include "logging.h"
#include "objectLayer.h"
#include "symbols.h"


int enemiesReached = 0;
int enemiesKilled = 0;

void defProjLayer()
{
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            projectileLayer[i][j] = 'a';
        }
    }
}

void advanceGame(char level[SIZE][SIZE])
{

    int i, j;
    static int ctr = 0;

    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            char c = level[i][j];
            if (c == crumb1) {
                level[i][j] = crumb2;
            } else if (c == crumb2){
                level[i][j] = path;
            } else if (isShooter(c) && (ctr % 3 == 0)) {
                fireShooter(i, j);
            } else if (isEnemy(c)) {
                advanceEnemy(level, i, j);
            }
        }
    }

    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (level[i][j] == walker - 32) {
                level[i][j] = walker;
            }
        }
    }
    if (ctr % 5 == 0) spawnEnemy(level);

    ctr++;
}

void spawnEnemy(char level[SIZE][SIZE])
{
    //find the start
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (level[i][j] == start) goto start_found;
        }
    }

start_found: ;
    int pathx = -1;
    int pathy = -1;
    getPathAround(level, i, j, &pathx, &pathy);
    if (pathx >= 0 || pathy >= 0) {
        level[pathx][pathy] = walker;

        enemy * e = newEnemy(pathx, pathy);
        addObject((void *) e, e->type);
    }
}

int isEnemy(char c)
{
    if (c == walker) return 1;
    return 0;
}

int isShooter(char c)
{
    if (strchr("NESW", c) != NULL) return 1;
    return 0;
}

void fireShooter(int x, int y)
{
    /* printf("found tower at x: %d, y: %d", x, y); */
    activateObject(1, x, y);
}

int hitWalker(char level[SIZE][SIZE], int x, int y)
{
    int ret = activateObject(2, x, y);
    if (ret == 0) {
        level[x][y] = path;
        enemiesKilled++;
        currEnergy++;
        writeLog("Removing enemy!");
    }
    return ret;
}

void advanceEnemy(char level[SIZE][SIZE], int i, int j)
{

    int pathx = -1;
    int pathy = -1;
    getPathAround(level, i, j, &pathx, &pathy);
    if (pathx >= 0 || pathy >= 0) {
        level[i][j] = crumb1;
        level[pathx][pathy] = walker - 32;
        moveObject(i, j, pathx, pathy);
    } else {
        //we are one char away from the end
        level[i][j] = path;
        deleteObject(i, j);
        enemiesReached++;
    }
}

void getPathAround(char level[SIZE][SIZE], int i, int j, int * pathx, int * pathy)
{
    int x1 = i - 1;
    int x2 = i + 1;
    int y1 = j - 1;
    int y2 = j + 1;
    if (isValid(x1)) {
        if (level[x1][j] == path) {
            *pathx = x1;
            *pathy = j;
        }
    } if (isValid(x2)) {
        if (level[x2][j] == path) {
            *pathx = x2;
            *pathy = j;
        }
    } if (isValid(y2)) {
        if (level[i][y2] == path) {
            *pathx = i;
            *pathy = y2;
        }
    } if (isValid(y1)) {
        if (level[i][y1] == path) {
            *pathx = i;
            *pathy = y1;
        }
    }
}

int isValid(int x)
{
    if (x < 0 || x >= SIZE) return 0;
    return 1;
}

