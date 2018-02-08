#include <loadScreen.h>

int loadScreen(struct Options * O) {
    // initialize the ncurses system
    initscr();
    noecho();
    curs_set(FALSE); 
        
    if (O->skipSplashScreen) return 1;
    
    // show the load screen
    
    
    return 1;
}
