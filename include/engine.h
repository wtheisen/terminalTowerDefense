#ifndef engine_h
#define engine_h

#include "levelGen.h"

extern int enemiesReached;
extern int enemiesKilled;
char projectileLayer[SIZE][SIZE];

void defProjLayer();
void advanceGame(char level[SIZE][SIZE]);

void spawnEnemy(char level[SIZE][SIZE]);
int isEnemy(char c);
int isShooter(char c);
void fireShooter(int x, int y);
int hitWalker(int x, int y);
void advanceEnemy(char level[SIZE][SIZE], int, int);

void getPathAround(char level[SIZE][SIZE], int, int, int *, int *);

int isValid(int);


#endif
