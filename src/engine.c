#include "engine.h"
#include "logging.h"
#include "symbols.h"

void advanceGame(char level[SIZE][SIZE]) {
    writeLog("Advancing game");

    int i, j;
    static int ctr = 0;

    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            char c = level[i][j];
            if (c == placeholder) {
                //level[i][j] = path;
            } else if (isEnemy(c)) {
                advanceEnemy(level, i, j, c); 
                goto end;
            }


        }
    }
end: ;
    if (ctr == 0) spawnEnemy(level);
    ctr++;
}

void spawnEnemy(char level[SIZE][SIZE]) {
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
        writeLog("Spawning an enemy");
        level[pathx][pathy] = walker;
    }
}

int isEnemy(char c) {
    if (c == walker) return 1; 
    return 0;    
}

void advanceEnemy(char level[SIZE][SIZE], int i, int j, char c) {

    int pathx = -1;
    int pathy = -1;
    getPathAround(level, i, j, &pathx, &pathy);
    if (pathx >= 0 || pathy >= 0) {
        writeLog("Advancing Enemy");
        level[i][j] = placeholder;
        level[pathx][pathy] = c;
    }
}

void getPathAround(char level[SIZE][SIZE], int i, int j, int * pathx, int * pathy) {
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

int isValid(int x) {
    if (x < 0 || x >= SIZE) return 0;
    return 1;
}
