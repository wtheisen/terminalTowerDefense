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

int main(int argc, char * argv[])
{
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

    initObjectLayer();
     

    loadScreen(&Opt);

    /* tower test = {'t', 0, 0, NORTH, shoot}; */

    /* test.shoot(&test); */

    char level[SIZE][SIZE];
    levelGen(level);
    addTowers(level);


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


