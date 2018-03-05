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
    init_pair(4, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(5, COLOR_YELLOW, COLOR_BLACK);
    //init_color(COLOR_BLUE, 255, 140, 0);
    init_pair(6, COLOR_BLUE, COLOR_BLACK);
    init_color(COLOR_BLUE, 255, 140, 0);

    /* init_pair(4, COLOR_GREEN, COLOR_BLACK); */

    initObjectLayer();

    loadScreen(&Opt);

    /* tower test = {'t', 0, 0, NORTH, shoot}; */

    /* test.shoot(&test); */

    char level[SIZE][SIZE];
    levelGen(level);
    int enemiesInWave = 3;
    currWave = 1;

    while (!stop)
    {
	if (enemiesReached >= 10)
	{
		stop = 0;
		break;
	}

        int spawnFactor = 5;
        enemiesSpawnedWave = 0;

        enemiesRemaining = enemiesInWave - enemiesSpawnedWave;
        addTowers(level);
        defProjLayer();

        // while (enemiesSpawnedWave < enemiesInWave) {
        // enemiesRemaining = enemeies to be spawned
        // enemiesInWave = # of enemies in complete wave
        // enemiesSpawnedWave = enemies spawned thus far 
        
        while(enemiesRemaining) {
	    if (enemiesReached == 10)
        {
            stop = 0;
            break;
        }

            usleep(100000);
            enemiesSpawnedWave = advanceGame(level, spawnFactor);
            enemiesRemaining = enemiesInWave - enemiesSpawnedWave;
            drawGrid(level);
        }

        while (getEnemiesOnBoard(level) && stop) {
            usleep(100000);
            advanceGame(level, 100000);
            drawGrid(level); 
        }

        enemiesInWave += 2;
        currWave++;
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

