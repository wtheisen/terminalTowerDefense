#include "commandOptions.h"
#include "levelGen.h"
#include "loadScreen.h"

int drawGrid();

int main(int argc, char * argv[])
{
    // parse user options
    struct Options Opt = getCommandArguments(argc, argv);

    loadScreen(&Opt);

    drawGrid();
    sleep(3);

    levelGen();

    // clean-up
    cleanup(&Opt);

    return 0;
}

int drawGrid()
{
    int mx=0, my=0;

    getmaxyx(stdscr, mx, my);

    int i = 0, j = 0;
    for (i = 0; i < my; i+=2) {
        mvhline(i, 0, '-', mx);
    }

    for (j = 0; j < mx; j+=2) {
        mvvline(0, j, '|', my);
    }

    refresh();

    return 1;
}
