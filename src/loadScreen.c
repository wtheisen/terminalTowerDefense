#include <loadScreen.h>

int loadScreen(int skip) {
    // initialize the ncurses system
    initscr();
    noecho();
    curs_set(FALSE); 
        
    if (skip) return 1;
    
    // show the load screen
    
    
    return 1;
}
