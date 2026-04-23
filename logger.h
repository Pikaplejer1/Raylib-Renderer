#pragma once
#include "mathD.h"

#include <stdarg.h>

typedef enum{
    INFO,
    DEBUG,
    ERROR,
    WARNING,
    All,
    NONE
}LEVEL;

void logger(const LEVEL level,const char *format, ...);
void logger_vec2(const LEVEL level,const char *format, const Vec2 vector);
void logger_vec3(const LEVEL level,const char *format, const Vec3 vector);
void logger_vec4(const LEVEL level,const char *format, const Vec4 vector);
void setLogLevel(LEVEL level);