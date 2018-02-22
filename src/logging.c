#include <stdio.h>
#include <time.h>
#include <unistd.h>

#include "logging.h"

FILE * logFilePtr;

int initLog()
{
    char logFile[] = LOG_DIR LOG_FILENAME;

    FILE * fp;
    fp = fopen(logFile, "w");
    logFilePtr = fp;

    if (!fp) {
        #undef LOG_DIR
        #define LOG_DIR "../logging/"
        char logFile2[] = LOG_DIR LOG_FILENAME;
        fp = fopen(logFile2, "w");
        logFilePtr = fp;
        if (!fp) {
            printf("Error creating log file...");
            return 0;
        }
    }

    writeLog(__LINE__, __func__, "Log Created");
    return 1;
}

int closeLog()
{
    if (fclose(logFilePtr)) {
        return 1;
    }
    return 0;
}

void writeLog(const int lineNum, const char * callFunc, char * message)
{
    char timeStr[50];
    time_t curTime = time(0);
    strftime(timeStr, 50, "%H:%M:%S", localtime(&curTime));
    if (!fprintf(logFilePtr, "%s:%d -- %s -- %s\n", callFunc, lineNum, timeStr, message)) {
        printf("Error writing to log...");
    }
    fflush(logFilePtr);
    /* fprintf(logFilePtr, "%s -- %s -- %s\n", message, timeStr, __func__); */
}
