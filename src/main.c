#include <signal.h>

#include "commandOptions.h"
#include "draw.h"
#include "engine.h"
#include "levelGen.h"
#include "loadScreen.h"
#include "mouse.h"
#include "objectLayer.h"
#include "tower.h"
#include "logging.h"

void* objectMask[32][32];

WINDOW * win = NULL;
static volatile int stop = 0;

void handler(int);

int main(int argc, char * argv[])
{
    signal(SIGINT, handler);

    win = initscr();

    // parse user options
    struct Options Opt = getCommandArguments(argc, argv);

    if (!initLog()) {
        puts("Error creating log file! Exiting ...");
        return 1;
    } else if (has_colors() == FALSE) {
        puts("Terminal doesn't support colors! Exiting ...");
        return 1;
    }

    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_CYAN, COLOR_BLACK);
    /* init_pair(4, COLOR_GREEN, COLOR_BLACK); */

    initObjectLayer();

    loadScreen(&Opt);

    /* tower test = {'t', 0, 0, NORTH, shoot}; */

    /* test.shoot(&test); */

    char level[SIZE][SIZE];
    levelGen(level);
    addTowers(level);
    defProjLayer();

    int spawnFactor = 5;
    enemiesSpawnedWave = 0;

    while (!stop) {
        sleep(1);
        advanceGame(level, spawnFactor);
        drawGrid(level);
    }

    // clean-up
    freeObjects();
    cleanup(&Opt);
    closeLog();

    return 0;
}

void handler(int sig) {
    (void) sig;
    stop = 1;
}

