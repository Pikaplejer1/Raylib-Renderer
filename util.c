
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

#include "global.h"
#include "util.h"



Color getCircularColor(){
    double dt = GetTime()*0.5;
    float r= sin(dt)*127.5 +127.5;
    float g= sin(dt*2)*127.5 + 127.5;
    float b= sin(dt*4)* 127.5+127.5;
    Color c = {r,g,b,255};
    return c;
}

void swapInt(int* x0, int* x1){
    int temp = *x0;
    *x0= *x1;
    *x1 = temp;
}

Vec2 getRandomPos(){
    int x0;
    int y0; 
    x0 = round(rand()%SCREEN_WIDTH);
    y0 = round(rand()%SCREEN_HEIGHT);
    printf("x0: %d, y0: %d\n",x0,y0);
    return (Vec2){x0,y0};

}

Color getRandomColor(){
    int r=rand()%255;
    int g=rand()%255;
    int b=rand()%255;
    return (Color){r,g,b,255};
}


