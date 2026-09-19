
#include "AllImports.h"


int main(int argc, char **argv){
    Color col[10];
    for(int i=0; i<10; i++){
        col[i] = getRandomColor();
    }
    // access it: framebuffer[i*screen_width + j]
    InitWindow(SCREEN_WIDTH,SCREEN_HEIGHT, "atari brakeout type shit ");
    SetTargetFPS(144);

    innitAllBuffers(); // innit frame buffer and z buffer 

    innitImg();
    srand(time(NULL));
    // createGradientTest(RED, BLUE);
    
    /*x0: 634, y0: 89
    x0: 282, y0: 47
    x0: 406, y0: 344*/
    //(Vector2){634,89},(Vector2){282,47},(Vector2){406,344}
    // for(int i=0;i<5;i++)
    //     drawFilledTriangle(getRandomPos(),getRandomPos(),getRandomPos(), getRandomColor());
    
   

    Vec3 *cubeVertices = testCube.vertices;
    int (*cubeFaces)[4] = testCube.faces;
    int (*cubeEdges)[2] = testCube.edges;

    Vec3 mass = {0,0,0};
    Vec2 projected[8];
    for(int i=0; i<8;i++){
        mass.x +=cubeVertices[i].x;
        mass.y +=cubeVertices[i].y;
        mass.z +=cubeVertices[i].z;
    }
    Vec3 centre = {mass.x/8, mass.y/8, mass.z/8};
    logger_vec3(DEBUG, "x:%f, y:%f, :%f", centre);
    Mat4 translationToCentre = mat4_translate(-centre.x, -centre.y, -centre.z);
    Mat4 translationToOrigin = mat4_translate(centre.x, centre.y,centre.z);
    ProjectedVertex toDraw[8];
    
    while(!WindowShouldClose()){
        Mat4 rotate_x = mat4_identity();//mat4_rotate_x(GetTime());
        Mat4 rotate_y =mat4_rotate_y(GetTime()/2);
        Mat4 rotate_z =mat4_rotate_z(GetTime()/3);
        for(int i=0;i<8;i++){
            Mat4 transformationMatrix = 
                mat4_multiply(rotate_z,
                mat4_multiply(rotate_y,rotate_x));
                        
            Vec4 verticesVec4 = vec3_to_vec4( cubeVertices[i]);
            Vec4 newPos = mat4_mul_vec4(translationToCentre, verticesVec4);
            newPos = mat4_mul_vec4(transformationMatrix, newPos);
            newPos = mat4_mul_vec4(translationToOrigin, newPos);
            Vec3 newPosVec3 = vec4_to_vec3(newPos);
            
            ProjectedVertex projectedVertex = project(newPosVec3,FOV);
            toDraw[i] = projectedVertex;

        }
        for(int i=0;i<8;i++){
            writeThickPixel(toDraw[i].point, 36, RED);
        }
        for(int i=0; i<6;i++){
            // Vec2 A,B,C,D;
            // A= toDraw[cubeFaces[i][0]];
            // B= toDraw[cubeFaces[i][1]];
            // C= toDraw[cubeFaces[i][2]];
            // D= toDraw[cubeFaces[i][3]];
            // drawFilledTriangle(A,B,C, RED,YELLOW);
            // drawFilledTriangle(A,D,C, RED,YELLOW);
            drawFace(toDraw, cubeFaces[i], col[i]);
        }
        rlDrawingAPI();
    }
}