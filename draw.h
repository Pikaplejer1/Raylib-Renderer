#pragma once
#include <raylib.h>
#include "mathD.h"


void drawLineV(Vec2 a, Vec2 b, Color c);
void drawLineH(Vec2 a, Vec2 b, Color c);
void drawLine(Vec2 a, Vec2 b, Color c);
void createColorCycleTest();
void createGradientTest(Color c1, Color c2);
void createPolarSphere();
void drawTriangle(Vec2 A, Vec2 B, Vec2 C, Color col);
void drawFilledTriangle(ProjectedVertex APoint, ProjectedVertex BPoint, ProjectedVertex CPoint, Color outlineCol, Color fillCol);


void drawFace(ProjectedVertex *pointsToDraw, int *face, Color c);


void writeThickPixel(Vec2 a, int thickness, Color c);
void writePixel(Vec2 a, Color c);
void writeDepthPixel(Vec2 a, float z, Color c);