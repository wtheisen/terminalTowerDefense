#ifndef engine_h
#define engine_h

#include <string.h>
#include "levelGen.h"

extern int enemiesReached;
extern int enemiesKilled;
extern int enemiesSpawnedWave;
extern int enemiesRemaining;
extern int currEnergy;
extern int currWave;
char projectileLayer[SIZE][SIZE];

void defProjLayer();
int advanceGame(char level[SIZE][SIZE], int spawnFactor);

void spawnEnemy(char level[SIZE][SIZE]);
int isEnemy(char c);
int isShooter(char c);
void fireShooter(int x, int y);
int hitWalker(char level[SIZE][SIZE], int x, int y);
void advanceEnemy(char level[SIZE][SIZE], int, int);

void getPathAround(char level[SIZE][SIZE], int, int, int *, int *);

int isValid(int);
int getEnemiesOnBoard(char level[SIZE][SIZE]);

#endif
