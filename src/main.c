#include "commandOptions.h"
#include "draw.h"
#include "engine.h"
#include "levelGen.h"
#include "loadScreen.h"
#include "logging.h"

int main(int argc, char * argv[])
{
    // parse user options
    struct Options Opt = getCommandArguments(argc, argv);

    if (!initLog()) {
        puts("Error creating log file! Exiting ...");
        return 1;
    }

    loadScreen(&Opt);


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


