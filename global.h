#pragma once
#include "raylib.h"

#define SCREEN_WIDTH 2048
#define SCREEN_HEIGHT 2048
#define FOV 80

#define MIN(a,b) (((a) < (b)) ? (a) : (b))
#define MAX(a,b) (((a) > (b)) ? (a) : (b))

extern Color *framebuffer;
extern Texture2D tex;