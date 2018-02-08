#include <loadScreen.h>

int loadScreen(struct Options * Opt)
{
    // initialize the ncurses system
    
    if (!Opt->disableNCurses) {
        initscr();
        noecho();
        curs_set(FALSE); 
    }
    
    if (Opt->skipSplashScreen) return 1;
    
    // show the load screen
    
    
    return 1;
}

void cleanup(struct Options * Opt)
{
    if (!Opt->disableNCurses) {
        endwin();
    }
}
