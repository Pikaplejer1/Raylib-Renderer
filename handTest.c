#include "AllImports.h"

int main(){
    Vec3 cameraPos = (Vec3){0,0,0};
    Vec3 *cubeVertices = testCube.vertices;
    int (*cubeFaces)[4] = testCube.faces;
    int (*cubeEdges)[2] = testCube.edges;

    printf("the result of tocamera is: %d", vec3_minus(cameraPos,cubeVertices[0]));
}