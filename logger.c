#include "logger.h"
#include <stdio.h>

#define RED   "\033[0;31m"
#define GRN   "\033[0;32m"
#define YEL   "\033[0;33m"
#define BLU   "\033[0;34m"
#define RESET "\033[0m"

LEVEL logLevel =DEBUG;

void logger(const LEVEL level,const char *format, ...){
    va_list args;
    va_start(args,format);
    if(logLevel!= level) return;
    switch (level)
    {
    case (INFO):
        printf(BLU "[%s] ", "INFO" RESET);
        break;
    
    case (DEBUG):
        printf(GRN "[%s] ", "DEBUG" RESET);
        break;
    
    case (ERROR):
        printf(RED "[%s] ", "ERROR" RESET );
        break;
    case (WARNING):
        printf(YEL "[%s] ", "WARNING" RESET);
        break;
    default:
        break;
    }
    vprintf(format, args);
    va_end(args);
    printf("\n");
};
void logger_vec2(const LEVEL level,const char *format, const Vec2 vector){
    logger(level, format, vector.x, vector.y);
}
void logger_vec3(const LEVEL level,const char *format, const Vec3 vector){
    logger(level, format, vector.x, vector.y, vector.z);
}
void logger_vec4(const LEVEL level,const char *format, const Vec4 vector){
    logger(level, format, vector.x, vector.y,vector.z,vector.w);
}


void setLogLevel(LEVEL level){
    logLevel = level;
}