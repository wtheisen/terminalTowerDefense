#ifndef commandOptions_h
#define commandOptions_h

#include <unistd.h> 

struct Options {
    int skipSplashScreen;
};

//struct Options Options_Default = {0};

void initOptions(struct Options *);
struct Options getCommandArguments(int, char **);

#endif
