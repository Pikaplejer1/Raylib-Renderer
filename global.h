#pragma once
#include "raylib.h"

#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 1024
#define MIN(a,b) (((a) < (b)) ? (a) : (b))
#define MAX(a,b) (((a) > (b)) ? (a) : (b))

extern Color *framebuffer;
extern Texture2D tex;