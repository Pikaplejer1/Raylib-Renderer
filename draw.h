#pragma once
#include <raylib.h>
#include "mathD.h"


void drawLineV(Vec2 a, Vec2 b, Color c);
void drawLineH(Vec2 a, Vec2 b, Color c);
void drawLine(Vec2 a, Vec2 b, Color c);
void createColorCycleTest();
void createGradientTest(Color c1, Color c2);
void createPolarSphere();
void writePixel(Vec2 a, Color c);
void drawTriangle(Vec2 A, Vec2 B, Vec2 C, Color col);
void drawFilledTriangle(Vec2 A, Vec2 B, Vec2 C, Color outlineCol, Color fillCol);
void writeThickPixel(Vec2 a, int thickness, Color c);
void resetBuffer();

void drawFace(Vec3 *vertices, int *faces, Color c);