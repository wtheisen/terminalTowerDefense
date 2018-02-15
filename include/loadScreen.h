#ifndef loadScreen_h
#define loadScreen_h

#include <ncurses.h>

#include "commandOptions.h"

int loadScreen(struct Options *);
void cleanup(struct Options *);

#endif
