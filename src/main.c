#include "commandOptions.h"
#include "loadScreen.h"

int main(int argc, char * argv[]) {
    // parse user options
    struct Options O = getCommandArguments(argc, argv); 
    
    loadScreen(&O);        
        
    // clean-up
    endwin();
    return 0;
}
