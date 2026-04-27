#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#include "global.h"
#include "util.h"
#include "draw.h"
#include "mathD.h"

void drawLineH(Vec2 a, Vec2 b, Color c){
    int x0 = a.x;
    int y0= a.y;
    int x1=b.x;
    int y1=b.y;
    if (x0>x1){
        swapInt(&x0,&x1);
        swapInt(&y0,&y1);
    }
    int dx = x1-x0;
    int dy = y1-y0;

    int dir = (dy<0) ? -1 : 1;
    dy *=dir;
    if(dx!=0){
        int y= y0;
        int p =2*dy - dx;
        for (int i=0; i<dx;i++){
            writePixel((Vec2){x0+i, y}, c);
            if(p>=0){
                y+=dir;
                p = p-2*dx;
            }
            p = p+2*dy;
        }
    }
}

void drawLineV(Vec2 a, Vec2 b, Color c){
    int x0 = a.x;
    int y0= a.y;
    int x1=b.x;
    int y1=b.y;
    if (y0>y1){
        swapInt(&x0,&x1);
        swapInt(&y0,&y1);
    }
    int dx = x1-x0;
    int dy = y1-y0;

    int dir = (dx<0) ? -1 : 1;
    dx *=dir;
    if(dy!=0){
        int x= x0;
        int p =2*dx - dy;
        for (int i=0; i<dy;i++){
            writePixel((Vec2){x, y0+i}, c);
            if(p>=0){
                x+=dir;
                p = p-2*dy;
            }
            p = p+2*dx;
        }
    }
}

void drawLine(Vec2 a, Vec2 b, Color c){
    int x0 = a.x;
    int y0= a.y;
    int x1=b.x;
    int y1=b.y;
    int absX = abs(x1-x0);
    int absY = abs(y1-y0);
    if(absX>absY){
        drawLineH(a,b, c);
    } else
        drawLineV(a,b, c);
}

void createGradientTest(Color c1, Color c2){
    double nR, nG, nB;
    for(int i=0;i<SCREEN_HEIGHT;i++){
        for(int j=0; j<SCREEN_WIDTH;j++){
            double step = (((double)(j+i))/2)/(SCREEN_WIDTH-1);
            
            nR = (1-step)*c1.r + step*c2.r;
            nG = (1-step)*c1.g + step*c2.g;
            nB = (1-step)*c1.b + step*c2.b;
            framebuffer[i*SCREEN_WIDTH+j] = (Color){nR,nG,nB,255};

        }
    }
}
void createColorCycleTest(){
    double dt = GetTime();
    float r= sin(dt)*127.5 +127.5;
    float g= sin(dt*2)*127.5 + 127.5;
    float b= sin(dt*4)* 127.5+127.5;
    for(int i=0; i<SCREEN_HEIGHT; i++){ 
        for(int j=0;j<SCREEN_WIDTH; j++){
            framebuffer[i*SCREEN_WIDTH+j] = (Color) {
                r,g,b,255
            };
        }
    }
}

void createPolarSphere(){
    int r= SCREEN_HEIGHT/2;
    int x0 = SCREEN_HEIGHT/2;
    int y0=SCREEN_HEIGHT/2;
    Vec2 centre = {SCREEN_WIDTH/2, SCREEN_HEIGHT/2};

    Color c = getCircularColor();
        for (int theta=0; theta<360;theta++){
            // printf("this work\n");
            float deg = theta*(PI/180);
            int y = round(r*sin(deg));
            int x = round( r*cos(deg));
            x+=SCREEN_WIDTH/2;
            y+= SCREEN_HEIGHT/2;
            Vec2 endpoint = {x,y};
            // printf("%d,%d,%d,%d\n",x0,y0,x,y);s
            // printf("theta: %d\n", theta); 
            drawLine(centre, endpoint, c);
        }
}
void resetBuffer(){
    for(int i=0; i<SCREEN_HEIGHT;i++){
        for(int j=0;j<SCREEN_WIDTH;j++){
            framebuffer[i*SCREEN_WIDTH+j] = WHITE;
        }
    }
}
    
void writePixel(Vec2 a, Color c){
    if(a.x < 0 || a.x >= SCREEN_WIDTH || a.y < 0 || a.y >= SCREEN_HEIGHT) return;

    int x=a.x;
    int y=a.y;
    framebuffer[y*SCREEN_WIDTH + x] = c;
}

void writeThickPixel(Vec2 a, int thickness, Color c){
    if(a.x < 0 || a.x >= SCREEN_WIDTH || a.y < 0 || a.y >= SCREEN_HEIGHT) return;
    thickness=(int) (thickness/2);
    int x=a.x;
    int y=a.y;
    for(int i=-thickness;i<thickness; i++){
        for(int j=-thickness; j<thickness; j++){
            int drawX = a.x + i;
            int drawY = a.y +j;
            if(drawX<0 || drawY<0 || drawX>=SCREEN_WIDTH || drawY >= SCREEN_HEIGHT) break;
            framebuffer[drawY*SCREEN_WIDTH + drawX] = c;
        }
    }
}


void drawTriangle(Vec2 A, Vec2 B, Vec2 C, Color col){
    // from A to B
    drawLine(A,B, col);
    // from A to C
    drawLine (A,C, col);
    //from B to C
    drawLine(C,B,col);
}


void drawFilledTriangle(Vec2 A, Vec2 B, Vec2 C, Color outlineCol, Color fillCol){
    //draw the outline:
    drawTriangle(A,B,C,outlineCol);
    // get the bounding box of the triangle, future idea try to follow f(x) that goes throg x_n and y_n
    int lowestY = MAX(MAX(A.y,B.y), C.y);
    int lowestX = MIN(MIN(A.x,B.x),C.x);
    int highestY = MIN(MIN(A.y, B.y), C.y);
    int highestX = MAX(MAX(A.x, B.x), C.x);

    
    float lambda_A;
    float lambda_B;
    float lambda_C;
    
    for(int i=highestY;i<lowestY;i++){
        for(int j=lowestX;j<highestX;j++){
            // printf("i:%d j:%d \n",i,j);
            //y -> i; x -> j
            Vec2 r ={j,i};
            getBaricentric(A,B,C,r,&lambda_A, &lambda_B, &lambda_C);
            // printf("LambdaA:%5f ;LambdaB:%5f ;LambdaC:%5f\n ", lambda_A,lambda_B,lambda_C);
           
            if(
                (lambda_A >=0 && lambda_A <=1)  &&
                (lambda_B>=0 && lambda_B<=1)    &&
                (lambda_C>=0 && lambda_C<=1)){
                writePixel((Vec2){j,i},fillCol);
            }
        }
    }

}


void drawFace(Vec2 *pointsToDraw, int *face, Color c){
    Vec2 A,B,C,D;
    A= pointsToDraw[face[0]];
    B= pointsToDraw[face[1]];
    C= pointsToDraw[face[2]];
    D= pointsToDraw[face[3]];
    drawFilledTriangle(A,B,C, TRANSPARENT,c);
    drawFilledTriangle(A,C,D, TRANSPARENT,c);
    drawFilledTriangle(A,B,D, TRANSPARENT,c);
    drawFilledTriangle(D,B,C, TRANSPARENT,c);
    
}