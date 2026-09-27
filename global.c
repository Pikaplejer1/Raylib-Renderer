#include "global.h"
#include "mathD.h"

Color *framebuffer;
Texture2D tex;
float *zBuffer;
Vec3 cameraPos = {0,0,0};
Vec3 lightSource = {0.5,-1, -0.3};