#include "fileRead.h"
#include "logger.h"

#include <stdio.h>
#include <stdlib.h>

FILE *f; 
obj object;

int maxVertexIndex=0;
int maxFaceIndex=0;

int faceIndex=0;
int vertexIndex=0;

const int triangleIndexCount=3;



int setupFile(char* filename){
    float x,y,z;
    int q,w,r;

    maxVertexIndex=0;
    maxFaceIndex=0;

    faceIndex=0;
    vertexIndex=0;

    f=fopen(filename, "r");
    if(f==NULL){
        object.innitialised=0;
        //file not exist
        return -1;
    }else
        object.innitialised=1;
    
    char line[256];
    while(fgets(line,sizeof(line),f) != NULL){
        if(sscanf(line, "v %f %f %f",&x,&y,&z)==3)
            maxVertexIndex++;

        if(sscanf(line,"f %d %d %d",&q,&w,&r)==3)
            maxFaceIndex++;
    }
    //move the pointer to the beginning
    rewind(f);
    return 0;
}

void breakDown(){
    maxVertexIndex=0;
    maxFaceIndex=0;

    faceIndex=0;
    vertexIndex=0;
    fclose(f);
}

void freeObj(obj *o){
    if(o==NULL) return;
    for(int i=0; i<o->faceCount;i++) free(o->triangleIndices[i]);
    free(o->vertices);
    free(o->triangleIndices);
    free(o);
}

int getObjectFileFromName(char* filename, obj** object){
    //file doesn't exit
    if(setupFile(filename) !=0) 
        return -4;


    *object= NULL;
    obj *c = malloc(sizeof(obj));


    if(!c){
        logger(ERROR, "Not enough space to allocate object: obj");
        //not enough space 
        return -1;
    }
    c->innitialised =1;
    c->triangleIndices =NULL;
    c->vertices = NULL;


    c->vertices = malloc(maxVertexIndex * sizeof(Vec3));
    c->triangleIndices = malloc (maxFaceIndex* sizeof(int *));

    if(!c->vertices){
        logger(ERROR, "Not enough space to allocate vertices of an obj");
        //not enough space  vertices
        return -2;
    }
    if(!c->triangleIndices){
        logger(ERROR, "Not enough space to allocate triangleIndices");
        //not enough space triangle index
        return -3;
    }
    for (int i = 0; i < maxFaceIndex; i++) {
        c->triangleIndices[i] = malloc(triangleIndexCount * sizeof(int));
        if(!c->triangleIndices[i]){
            logger(ERROR, "Not enough space to allocate triangleIndices table");
            //not enough space tripple of triangle index
            return -3;
        }
    }

    

    //read the actuall file
    char line[256];
        while(fgets(line,sizeof(line), f) != NULL){
            float x,y,z;
            if(sscanf(line, "v %f %f %f", &x, &y, &z)==3){
                Vec3 vertex = {x,y,z};
                c->vertices[vertexIndex] = vertex;
                vertexIndex++;
            }
            int q,w,r;
            if(sscanf(line, "f %d %d %d", &q, &w, &r)==3){
                c->triangleIndices[faceIndex][0] = q-1;
                c->triangleIndices[faceIndex][1] = w-1;
                c->triangleIndices[faceIndex][2] = r-1;
                faceIndex++;
            }
        }
    c->vertexCount = vertexIndex;
    c->faceCount = faceIndex;
    
    breakDown();
    *object=c;

    return 0;
}