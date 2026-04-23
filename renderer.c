
#include <raylib.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "global.h"
#include "draw.h"
#include "util.h"
#include "logger.h"

void rlDrawingAPI(){
    UpdateTexture(tex, framebuffer);
    BeginDrawing();
        DrawTexture(tex,0,0,WHITE);
    EndDrawing();   
    resetBuffer();
}

int edges[12][2] = {
    {0,3},{3,1},{1,2},{2,0},  // front face
    {5,4},{4,6},{6,7},{7,5},  // back face
    {0,5},{3,4},{1,6},{2,7}   // connecting edges
};

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




int main(int argc, int **argv){
    if(argc == 1) setLogLevel(NONE);
    else setLogLevel(argv[1]);
    
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
    
   

    Vec3 pVec3[8] = {
        {-125,125,250},
        { 125,-125,250},
        {-125,-125,250},
        { 125,125,250},
        { 125,125,500},
        {-125,125,500},
        { 125,-125,500},
        {-125,-125,500},
    };
    Vec3 mass = {0,0,0};
    Vec2 projected[8];
    for(int i=0; i<8;i++){
        mass.x +=pVec3[i].x;
        mass.y +=pVec3[i].y;
        mass.z +=pVec3[i].z;
    }
    Vec3 centre = {mass.x/8, mass.y/8, mass.z/8};
    logger_vec3(DEBUG, "x:%f, y:%f, :%f", centre);
    Mat4 translationToCentre = mat4_translate(-centre.x, -centre.y, -centre.z);
    Mat4 translationToOrigin = mat4_translate(centre.x, centre.y,centre.z);
    
    while(!WindowShouldClose()){
        Mat4 rotate_x =mat4_rotate_x(GetTime());
        Mat4 rotate_y = mat4_rotate_y(GetTime()/2);
        Mat4 rotate_z = mat4_rotate_z(GetTime()/3);
        for(int i=0;i<8;i++){
            
            Mat4 transformationMatrix = 
                mat4_multiply(translationToOrigin, 
                mat4_multiply(rotate_z,
                mat4_multiply(rotate_y, 
                mat4_multiply(rotate_x, 
                    translationToCentre))));

            logger_vec3(DEBUG,"\nVec3 original is:{%f,%f,%f}",pVec3[i]);


            // 4d vector 
            Vec4 pVec4 = vec3_to_vec4(pVec3[i]);
            logger_vec4(DEBUG,"Vec4 from Vec3 is:{%f,%f,%f,%f} ",pVec4);

            Vec4 transformed = mat4_mul_vec4(transformationMatrix,pVec4);
            logger_vec4(DEBUG,"Vec4 transformed is:{%f,%f,%f,%f} ",transformed);
            Vec3 vec3Rotated = vec4_to_vec3(transformed);
            logger_vec3(DEBUG,"Vec3 final is:{%f,%f,%f} ",vec3Rotated);
            projected[i] =  project(vec3Rotated,90);
            logger_vec2(DEBUG,"Projected vector2: {%f,%f}\n",projected[i]);
        }
        for(int i = 0; i < 12; i++)
            drawLine(projected[edges[i][0]], projected[edges[i][1]], BLUE);
        for(int i=0; i<8;i++)
            writeThickPixel(projected[i],36,RED);
        rlDrawingAPI();
    }
}