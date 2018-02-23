#include "commandOptions.h"
#include "draw.h"
#include "engine.h"
#include "levelGen.h"
#include "loadScreen.h"
#include "objectLayer.h"
#include "tower.h"
#include "logging.h"

void* objectMask[32][32];

int main(int argc, char * argv[])
{
    // parse user options
    struct Options Opt = getCommandArguments(argc, argv);

    if (!initLog()) {
        puts("Error creating log file! Exiting ...");
        return 1;
    }

    initObjectLayer();

    loadScreen(&Opt);

    /* tower test = {'t', 0, 0, NORTH, shoot}; */

    /* test.shoot(&test); */

    char level[SIZE][SIZE];
    levelGen(level);
    drawGrid(level);

    while (1) {
        sleep(1);
        advanceGame(level);
        drawGrid(level);
    }

    // clean-up
    closeLog();
    cleanup(&Opt);

    return 0;
}


