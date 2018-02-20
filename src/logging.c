#include <stdio.h>
#include <time.h>
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

    writeLog("Log Created");
    return 1;
}

void writeLog(char * message) {
    char timeStr[50];
    time_t curTime = time(0);
    strftime(timeStr, 50, "%H:%M:%S", localtime(&curTime));
    fprintf(logFilePtr, "%s -- %s\n", message, timeStr);
}
