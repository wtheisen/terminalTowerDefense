#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main()
{
    int w = 100;
    int h = 100;
    int lvlW = w / 5;
    int lvlH = h / 5;

    char level[lvlW][lvlH];

    int i = 0, j = 0;
    for (i = 0; i < lvlW; i++) {
        for (j = 0; j < lvlH; j++) {
            level[i][j] = 'a';
        }
    }

    int currDir = 0; //either 0 for straight, 1 for up, and 2 for down
    int currSegLen = 0;

    srand(time(NULL));
    int currRow = rand() % lvlH;

    for (i = 0; i < lvlW; i++, currSegLen++) {
        if (currSegLen  >= 5) {
            if (currDir == 0) {
                currDir = rand() % 3;
            } else {
                currDir = 0;
            }
            currSegLen = 0;
        }

        printf("curr dir: %d\n", currDir);

        if (currDir != 0) {
            level[currRow][i] = 'b';
            for (j = 0; j <= 5; j++) {
                if (currDir == 2) {
                    printf("drawing up\n");
                    if (currRow - 2 <= 0) {
                        currDir = 0;
                        currSegLen = 0;
                        level[currRow][i] = 'b';
                        break;
                    } else {
                        currRow -= 1;
                    }
                } else {
                    if (currRow + 2 >= lvlH) {
                        currDir = 0;
                        currSegLen = 0;
                        level[currRow][i] = 'b';
                        break;
                    } else {
                        currRow += 1;
                    }
                }
                level[currRow][i] = 'b';
            }
            level[currRow][i] = 'b';
            continue;
        }

        level[currRow][i] = 'b';
    }

    for (i = 0; i < lvlH; i++) {
        for (j = 0; j < lvlW; j++) {
            printf("%c ", level[i][j]);
        }
        printf("\n");
    }

    return 0;
}
