
#include <raylib.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "global.h"
#include "draw.h"
#include "util.h"

void rlDrawingAPI(){
    UpdateTexture(tex, framebuffer);
    BeginDrawing();
        DrawTexture(tex,0,0,WHITE);
    EndDrawing();   
}

void innitBuffer(){
    framebuffer = (Color *) malloc(
        SCREEN_HEIGHT*sizeof(Color) *
        SCREEN_WIDTH
    );

}


void innitImg(){
    Image img = {
        .data = framebuffer,
        .format = PIXELFORMAT_UNCOMPRESSED_R8G8B8A8,
        .width = SCREEN_WIDTH,
        .height = SCREEN_HEIGHT,
        .mipmaps =1
    };
    tex =LoadTextureFromImage(img);
}




int main(){
    
    // access it: framebuffer[i*screen_width + j]
    InitWindow(SCREEN_WIDTH,SCREEN_HEIGHT, "atari brakeout type shit ");
    SetTargetFPS(144);
    innitBuffer(); // innit framebuffer 
    innitImg();
    srand(time(NULL));
    // createGradientTest(RED, BLUE);
    
    /*x0: 634, y0: 89
    x0: 282, y0: 47
    x0: 406, y0: 344*/
    //(Vector2){634,89},(Vector2){282,47},(Vector2){406,344}
    // for(int i=0;i<5;i++)
    //     drawFilledTriangle(getRandomPos(),getRandomPos(),getRandomPos(), getRandomColor());
    
   

    Vec2 p ={SCREEN_HEIGHT/2, SCREEN_WIDTH/2};
    writeThickPixel(p, 10, RED);
    
    while(!WindowShouldClose()){
        rlDrawingAPI();
    }

}