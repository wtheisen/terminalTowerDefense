#ifndef logging_h
#define logging_h

#include <stdio.h>

#define LOG_FILENAME "log"
#define LOG_DIR "logging/"

extern FILE * logFilePtr;

int initLog();
void  writeLog(char *);

#endif
