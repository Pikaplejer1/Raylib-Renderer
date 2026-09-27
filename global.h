#pragma once
#include "raylib.h"
#include "mathD.h"

#define SCREEN_WIDTH 2048
#define SCREEN_HEIGHT 2048
#define FOV 80
#define TRANSPARENT (Color){0,0,0,0}


#define MIN(a,b) (((a) < (b)) ? (a) : (b))
#define MAX(a,b) (((a) > (b)) ? (a) : (b))

extern float *zBuffer;
extern Color *framebuffer;
extern Texture2D tex;
extern Vec3 cameraPos;
extern Vec3 lightSource;