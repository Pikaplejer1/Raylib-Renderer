
#include "AllImports.h"

#include "main.h"




Vec3* vertices;
int** triangleIndices;
int innitialised;

int vertexCount;
int faceCount;

ProjectedVertex* projectedVertexToDraw = NULL;
Vec3* depthVertices = NULL;
Color* col = NULL;
float* brightness = NULL;

int rotationEnabled=0;

void seedColour(){
    for(int i=0; i<faceCount; i++){
        col[i] = getRandomColor();
    }
}

void envSetup(){
    InitWindow(SCREEN_WIDTH,SCREEN_HEIGHT, "atari brakeout type shit ");
    SetTargetFPS(144);
    innitAllBuffers(); // innit frame buffer and z buffer 
    innitImg();
    srand(time(NULL)); 
    setTransformationToIdentity();
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
    col = malloc(faceCount*sizeof(Color));
    brightness = malloc(faceCount*sizeof(float));
    if(col == NULL )return -1;
    return 0;
}

Vec3 centreOfMass;
Mat4 translationToCentre;
Mat4 translationToOrigin;
Mat4 transformationMatrix;

void prepareCentreOfMass(){
    centreOfMass = getCentreMass(vertices, vertexCount);
}

void prepareRotationMatrix(){
    // Mat4 rotate_x = mat4_rotate_x(GetTime());
    // Mat4 rotate_y =mat4_rotate_y(GetTime()/2);
    // Mat4 rotate_z =mat4_rotate_z(GetTime()/3);
    
    transformationMatrix =  mat4_rotate_y(GetTime());
        // mat4_multiply(rotate_z,
        // mat4_multiply(rotate_y,rotate_x));
}
void prepareTranslationMatrices(){
    translationToCentre = mat4_translate(-centreOfMass.x, -centreOfMass.y, -centreOfMass.z);
    translationToOrigin = mat4_translate(centreOfMass.x, centreOfMass.y,centreOfMass.z);
}

void prepareMatrices(){
    
    prepareCentreOfMass();
    prepareRotationMatrix();
    prepareTranslationMatrices();
}

void setTransformationToIdentity(){
    transformationMatrix = mat4_identity();
    translationToCentre = mat4_identity();
    translationToOrigin = mat4_identity();
}

int getRandomColourValue(){
    int random =rand()%255+1;
    return random;
}


int main(int argc, char **argv){

    envSetup();
    
    obj* loaded = NULL;
    loadFile(".obj/utah_teapot.obj", &loaded);
    if(loaded==NULL) logger(DEBUG, "the loaded value is null");

    readObjValues(loaded);
    if(mallocTheVertices()!= 0 ) logger(WARNING, "Malloc of vertices returned !=0!");
    
    seedColour();
    
    while(!WindowShouldClose()){
        transformationMatrix = mat4_multiply(  
        mat4_rotate_y(GetTime()), mat4_rotate_x(1.4));

        // if (rotationEnabled) prepareRotationMatrix();
        for(int i=0; i<vertexCount; i++){

            Mat4 modelScale = mat4_scale(100, 100, 100);
            Mat4 translate = mat4_translate(0,100,600);
            centreOfMass= getCentreMass(vertices, vertexCount);
            Vec4 v4 = vec3_to_vec4(vertices[i]);
            v4 = mat4_mul_vec4(translationToCentre, v4);
            v4 = mat4_mul_vec4(modelScale, v4);
            v4 = mat4_mul_vec4(transformationMatrix, v4);
            v4 = mat4_mul_vec4(translate, v4);

            Vec3 v3 = vec4_to_vec3(v4);

            projectedVertexToDraw[i] = project(v3,80);
            depthVertices[i] = v3;
        }
        for(int i=0; i<faceCount;i++){
            // logger(DEBUG, "The indices of the triangles are as follows{%d, %d, %d}", triangleIndices[i][0], triangleIndices[i][1],triangleIndices[i][2]);
            // if(i<vertexCount)
            //     logger_vec2(DEBUG, "the values are as follows: %f, %f", projectedVertexToDraw[i].point);
            Vec3 A, B, C;
            A = depthVertices[triangleIndices[i][0]];
            B = depthVertices[triangleIndices[i][1]];
            C = depthVertices[triangleIndices[i][2]];
            float facingValue = getFacing(A,B,C);
            Vec3 normalizedNormal = getNormalizedNormalVec3(A,B,C);
            // logger_vec3(DEBUG, "the values for the normalized normal are as follows: %f, %f, %f", normalizedNormal);
            brightness[i] = vec3_dot(normalizedNormal, (Vec3){-lightSource.x, -lightSource.y, -lightSource.z});
            if(brightness[i]<0) brightness[i] = -brightness[i];
            // logger(DEBUG, "the value of the brighness is:%f", brightness[i]);
            float rVal =getRandomColourValue() * brightness[i];
            float gVal= getRandomColourValue() * brightness[i];
            float bVal= getRandomColourValue() * brightness[i];
            // logger(DEBUG, "the vlue of the colours are : r: %f, g: %f, b:%f", rVal,gVal,bVal);
            col[i] = (Color){rVal, gVal, bVal, 255};
            if(facingValue>=0)
                drawFace(projectedVertexToDraw,triangleIndices[i],col[i]);
            
            
        }
        
        rlDrawingAPI();
    }
}