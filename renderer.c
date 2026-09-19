
#include <raylib.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "renderer.h"
#include "global.h"
#include "draw.h"
#include "util.h"
#include "logger.h"
#include "objects.h"

void rlDrawingAPI(){
    UpdateTexture(tex, framebuffer);
    BeginDrawing();
    DrawTexture(tex,0,0,WHITE);
    EndDrawing();   
    resetAllBuffers();
}


void innitAllBuffers(){
    innitBuffer();
    innitZBuffer();
}

void innitBuffer(){
    framebuffer = (Color *) malloc(
        SCREEN_HEIGHT*sizeof(Color) *
        SCREEN_WIDTH
    );

}

void innitZBuffer(){
    zBuffer = (float*)malloc(
        SCREEN_HEIGHT*sizeof(float) *
        SCREEN_WIDTH
    );
}

void resetAllBuffers(){
    resetBuffer();
    resetZBuffer();
}



void resetBuffer(){
    for(int i=0; i<SCREEN_HEIGHT;i++){
        for(int j=0;j<SCREEN_WIDTH;j++){
            framebuffer[i*SCREEN_WIDTH+j] = WHITE;
        }
    }
}

void resetZBuffer(){
    for(int i=0; i<SCREEN_HEIGHT;i++){
        for(int j=0;j<SCREEN_WIDTH;j++){
            zBuffer[i*SCREEN_WIDTH+j] = INFINITY;
        }
    }
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





