#include "commandOptions.h"
#include "draw.h"
#include "levelGen.h"
#include "loadScreen.h"


int main(int argc, char * argv[])
{
    // parse user options
    struct Options Opt = getCommandArguments(argc, argv);

    loadScreen(&Opt);
    
    char level[SIZE][SIZE];
    levelGen(level);
    drawGrid(level);
    
    while (1) {
        sleep(3);
    }

    // clean-up
    cleanup(&Opt);

    return 0;
}


