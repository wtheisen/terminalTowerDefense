#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "levelGen.h"
#include "logging.h"
#include "symbols.h"

void levelGen(char level[SIZE][SIZE])
{
    writeLog(__LINE__, __func__, "Generating level");

    int lvlW = SIZE;
    int lvlH = SIZE;


    int i = 0, j = 0;
    for (i = 0; i < lvlW; i++) {
        for (j = 0; j < lvlH; j++) {
            setCoord(level, i, j, weeds);
        }
    }

    int currDir = 0; //either 0 for straight, 1 for up, and 2 for down
    int currSegLen = 0;

    srand(time(NULL));
    int currRow = rand() % lvlH;

    if (currRow == 0) {
        currRow++;
    } else if (currRow == lvlH - 1) {
        currRow--;
    }


    for (i = 0; i < lvlW; i++, currSegLen++) {
        if (currSegLen  >= 5 && i + 2 <= lvlW) {
            if (currDir == 0) {
                currDir = rand() % 3;
            } else {
                currDir = 0;
            }
            currSegLen = 0;
        }

        if (currDir != 0) {
            setCoord(level, currRow, i, path);
            for (j = 0; j <= 5; j++) {
                if (currDir == 2) {
                    //printf("drawing up\n");
                    if (currRow - 2 <= 0) {
                        currDir = 0;
                        currSegLen = 0;
                        setCoord(level, currRow, i, path);
                        break;
                    } else {
                        currRow -= 1;
                    }
                } else {
                    if (currRow + 2 >= lvlH) {
                        currDir = 0;
                        currSegLen = 0;
                        setCoord(level, currRow, i, path);
                        break;
                    } else {
                        currRow += 1;
                    }
                }
                setCoord(level, currRow, i, path);
            }
            setCoord(level, currRow, i, path);
            continue;
        }

        setCoord(level, currRow, i, path);
    }

    for (i = 0; i < lvlH; i++) {
        for (j = 0; j < lvlW; j++) {
            //printf("%c ", level[i][j]);
        }
        //printf("\n");
    }
}

void setCoord(char level[SIZE][SIZE], int x, int y, char c)
{
    static int pathStarted = 0;
    static int pathEnded = 0;

    //check if we should place the 'Start' char
    if (c == path) {
        if (!pathStarted)  {
            pathStarted = 1;
            c = start;
        }
        else if ((y == (SIZE-1) || y == 0) && pathStarted) {
            if (!pathEnded) {
                pathEnded = 1;
            }

            if (pathEnded) {
                // an 'End' char has already been placed
                if (x < SIZE - 2) {
                    if (level[x+1][y] == end) level[x+1][y] = path;
                }
                if (x > 0) {
                    if (level[x-1][y] == end) level[x-1][y] = path;
                }
            }
            c = end;
        }
    }
    level[x][y] = c;
}
