#ifndef logging_h
#define logging_h

#include <stdio.h>

#define LOG_FILENAME "log"
#define LOG_DIR "logging/"
#define writeLog(s) writeLogLong(__LINE__, __func__, s)


extern FILE * logFilePtr;

int initLog();
int closeLog();
void  writeLogLong(const int, const char*, char *);

#endif

