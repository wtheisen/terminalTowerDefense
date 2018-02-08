#include "commandOptions.h"
#include "levelGen.h"
#include "loadScreen.h"

int main(int argc, char * argv[]) {
    // parse user options
    struct Options Opt = getCommandArguments(argc, argv); 
    
    loadScreen(&Opt);        
    
    levelGen();

    // clean-up
    cleanup(&Opt);

    return 0;
}
