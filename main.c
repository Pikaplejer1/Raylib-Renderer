
#include "AllImports.h"

#define COUNT 12

Color col[COUNT];



Vec3* vertices;
int** triangleIndices;
int innitialised;

int vertexCount;
int faceCount;

ProjectedVertex* projectedVertexToDraw = NULL;
Vec3* depthVertices = NULL;

void seedColour(){
    for(int i=0; i<COUNT; i++){
        col[i] = getRandomColor();
    }
}

void envSetup(){
    InitWindow(SCREEN_WIDTH,SCREEN_HEIGHT, "atari brakeout type shit ");
    SetTargetFPS(144);
    innitAllBuffers(); // innit frame buffer and z buffer 
    innitImg();
    srand(time(NULL)); 
}


int counter =0; 

int loadFile(char* filename, obj** loaded){
    int result = getObjectFileFromName(filename, loaded);
    logger(INFO, "The file loaded with the result: %d", result);
    logger(INFO, "the value of the loaded obj face count is: %d", (*loaded)->faceCount);
    if(result==0) return 0;
    else return -1;
}

void readObjValues(obj* object){
    if(object==NULL) logger(WARNING, "the object pointer is null in readObjValues");
    faceCount= object->faceCount;
    logger(DEBUG, "face caount: %d", faceCount);
    vertexCount = object->vertexCount;
    vertices = object->vertices;
    triangleIndices = object->triangleIndices;
    logger(DEBUG, "this should run if all readobj vlues are correct");
}


int mallocTheVertices(){
    projectedVertexToDraw = malloc(vertexCount* sizeof(ProjectedVertex));
    if(projectedVertexToDraw == NULL )return -1;
    depthVertices = malloc(vertexCount*sizeof(Vec3));
    if(depthVertices == NULL )return -1;
    return 0;
}


int main(int argc, char **argv){

    envSetup();
    obj* loaded;
    seedColour();

    loadFile(".obj/testCube.obj", &loaded);
    if(loaded==NULL) logger(DEBUG, "the loaded value is null");
    readObjValues(loaded);
    
    int mallocResult = mallocTheVertices();
    logger(DEBUG, "The malloc of vertices resulted with: %d", mallocResult);
    logger(DEBUG, "the values of the counts are face/vertex: %d, %d", faceCount, vertexCount);
    
    
    while(!WindowShouldClose()){
        for(int i=0; i<vertexCount; i++){
            logger_vec3(DEBUG, "the values are as follows: %f, %f, %f", vertices[i]);
            Vec3 vertexToDraw = vertices[i];
    
            projectedVertexToDraw[i] = project(vertexToDraw,FOV);
            depthVertices[i] = vertexToDraw;
    
            // logger_vec2(DEBUG, "the value of projected vertexvertex: %f ,%f", projectedVertexToDraw[i].point);
            // writeDepthPixel(projectedVertexToDraw[i].point, projectedVertexToDraw[i].depth, RED);
        }
        for(int i=0; i<faceCount;i++){
            // logger(DEBUG, "The indices of the triangles are as follows{%d, %d, %d}", triangleIndices[i][0], triangleIndices[i][1],triangleIndices[i][2]);
            // if(i<vertexCount)
                // logger_vec2(DEBUG, "the values are as follows: %f, %f", projectedVertexToDraw[i].point);

            Vec3 A, B, C;
            A = depthVertices[triangleIndices[i][0]];
            B = depthVertices[triangleIndices[i][1]];
            C = depthVertices[triangleIndices[i][2]];
            float facingValue = getFacing(A,B,C);
            // logger(DEBUG, "the facing value is: %f", facingValue);
            if(facingValue >=0)
                drawFace(projectedVertexToDraw,triangleIndices[i],col[i]);
        }
        
        rlDrawingAPI();
    }
}