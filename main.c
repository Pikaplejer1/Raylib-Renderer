
#include "AllImports.h"


int main(int argc, char **argv){
    srand(time(NULL));
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
    
    int counter =0; 
    
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
    Vec3 rotatedVertices[8];
    while(!WindowShouldClose()){
        
        
        
        //build the rotation
        Mat4 rotate_x = mat4_rotate_x(GetTime());
        Mat4 rotate_y =mat4_rotate_y(GetTime()/2);
        Mat4 rotate_z =mat4_rotate_z(GetTime()/3);
        Mat4 transformationMatrix = 
            mat4_multiply(rotate_z,
            mat4_multiply(rotate_y,rotate_x));



        for(int i=0;i<8;i++){
            //convert the points to homogenous
            Vec4 verticesVec4 = vec3_to_vec4( cubeVertices[i]);

            //translate to centre
            Vec4 newPos = mat4_mul_vec4(translationToCentre, verticesVec4); 
            //main transformation of the vertices
            newPos = mat4_mul_vec4(transformationMatrix, newPos);
            //translate back to the original position 
            newPos = mat4_mul_vec4(translationToOrigin, newPos);


            //convert homogenous points back to normal points.
            Vec3 newPosVec3 = vec4_to_vec3(newPos);

            ProjectedVertex projectedVertex = project(newPosVec3,FOV);

            rotatedVertices[i] = newPosVec3;
            toDraw[i] = projectedVertex;

        }
        for(int i=0;i<8;i++){
            writeThickPixel(toDraw[i].point, 36, RED);
        }
        for(int i=0; i<6;i++){
            Vec3 A,B,C;
            counter++;
            if(counter>=144){
                int faceCounter=0;
                for(int i=0; i<6;i++){
                    if(getFacing(rotatedVertices[cubeFaces[i][0]],rotatedVertices[cubeFaces[i][1]],rotatedVertices[cubeFaces[i][2]])>0)
                        faceCounter++;
                }
                logger(DEBUG, "The number of visible faces at a moment is: %i", faceCounter);
                counter=0;
            }
            A = rotatedVertices[cubeFaces[i][0]];
            B = rotatedVertices[cubeFaces[i][1]];
            C = rotatedVertices[cubeFaces[i][2]];

            float facing = getFacing(A,B,C);
            if (facing>=0)
                drawFace(toDraw, cubeFaces[i], col[i]);

        }
        rlDrawingAPI();
    }
}