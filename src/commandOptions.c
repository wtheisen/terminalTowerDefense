#include "commandOptions.h"

void initOptions(struct Options * O) {
    O->skipSplashScreen = 0;
    O->disableNCurses = 0;
}

struct Options getCommandArguments(int argc, char ** argv)
{
    struct Options O;
    initOptions(&O);

    int opt;
    while ((opt = getopt (argc, argv, "sd")) != -1) {
        switch (opt) {
            case ('s'):
                O.skipSplashScreen = 1;
                break;
            case ('d'):
                O.disableNCurses = 1;
                break; 
        }
    }    
    
    return O;
}
