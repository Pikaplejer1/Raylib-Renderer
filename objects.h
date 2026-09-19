#pragma once
#include "mathD.h"



typedef struct 
{
    Vec3 vertices[8]; // pozycje 3D wierzchołków (lokalne, przed transformacją)

    int edges[12][2]; // pary indeksów -> które wierzchołki łączy krawędź (wireframe)

    int faces[6][4]; // czwórki indeksów -> które wierzchołki tworzą ścianę (quad)

} Cube;

extern Cube testCube;

