#ifndef engine_h
#define engine_h

#include "levelGen.h"

void advanceGame(char level[SIZE][SIZE]);

void spawnEnemy(char level[SIZE][SIZE]);
int isEnemy(char c);
void advanceEnemy(char level[SIZE][SIZE], int, int, char);

void getPathAround(char level[SIZE][SIZE], int, int, int *, int *);

int isValid(int);
#endif
