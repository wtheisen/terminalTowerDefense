#ifndef logging_h
#define logging_h

#include <stdio.h>

#define LOG_FILENAME "log"
#define LOG_DIR "logging/"

extern FILE * logFilePtr;

int initLog();
int closeLog();
void  writeLog(const int, const char*, char *);

#endif

