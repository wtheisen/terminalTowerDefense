#include <stdio.h>
#include <unistd.h>

#include "logging.h"

FILE * logFilePtr;

int initLog(){
    char logFile[] = LOG_DIR LOG_FILENAME; 
    
    FILE * fp; 
    fp = fopen(logFile, "w+");
    logFilePtr = fp;

    if (!fp) {
        #undef LOG_DIR
        #define LOG_DIR "../logging/"
        char logFile2[] = LOG_DIR LOG_FILENAME;
        fp = fopen(logFile2, "w+");
        logFilePtr = fp;
        if (!fp) return 0;       
    }
    return 1;
}

void writeLog(char * message) {
    fprintf(logFilePtr, "%s \n", message);
}
