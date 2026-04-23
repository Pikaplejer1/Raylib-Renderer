#pragma once
#include "mathD.h"



typedef struct 
{
    Vec3 vertices[8];
    int edges[12][2];
    int faces[6][4];
} Cube;

extern Cube testCube;
