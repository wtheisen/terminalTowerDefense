#ifndef objectLayer_h
#define objectLayer_h

#include "enemy.h"
#include "tower.h"
#include "levelGen.h"
#include "logging.h"

extern void * objLayer[SIZE][SIZE];

void initObjectLayer();
void addObject(void *, int);
void moveObject(int, int, int, int);
void deleteObject(int, int);

#endif
