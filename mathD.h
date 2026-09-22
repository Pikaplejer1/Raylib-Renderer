#pragma once


#define EPSILON 0.0001f
#define M_PI 3.1415926535f
#define DEG_TO_RAD(degrees) ((degrees) * M_PI / 180.0)

typedef struct  {float x,y;} Vec2;

typedef struct  {float x,y,z;} Vec3;

typedef struct  {float x,y,z,w;} Vec4;
typedef struct 
{
    float m[4][4];
} Mat4;


/**
 * Vec2 - point;
 * float- depth;
 */
typedef struct 
{
    Vec2 point;
    float depth;
} ProjectedVertex;


typedef struct{
    Vec3* vertices;
    int** triangleIndices;
    int innitialised;
    int vertexCount;
    int faceCount;
} obj;


float vec2_dot(Vec2 A, Vec2 B);
float vec2_cross(Vec2 A, Vec2 B);
Vec2 vec2_scalar(Vec2 A, float scalar);
Vec2 vec2_add(Vec2 A, Vec2 B);
Vec2 vec2_minus(Vec2 A, Vec2 B);
Vec2 vec2_normalize(Vec2 A);
float vec2_length(Vec2 A);
float vec2_length_sq(Vec2 A);

float vec3_dot(Vec3 A, Vec3 B);
Vec3 vec3_cross(Vec3 A, Vec3 B);
Vec3 vec3_scalar(Vec3 A, float scalar);
Vec3 vec3_add(Vec3 A, Vec3 B);
Vec3 vec3_minus(Vec3 A, Vec3 B);
Vec3 vec3_normalize(Vec3 A);
float vec3_length(Vec3 A);
float vec3_length_sq(Vec3 A);
Vec3 vec4_to_vec3(Vec4 A);

float vec4_dot(Vec4 A, Vec4 B);
Vec4 vec4_scalar(Vec4 A, float scalar);
Vec4 vec4_add(Vec4 A, Vec4 B);
Vec4 vec4_minus(Vec4 A, Vec4 B);
Vec4 vec4_normalize(Vec4 A);
float vec4_length(Vec4 A);
float vec4_length_sq(Vec4 A);

Mat4 mat4_identity();
Mat4 mat4_multiply(Mat4 A, Mat4 B);
Mat4 mat4_translate(float x, float y, float z);
Mat4 mat4_scale(float x, float y, float z);
Mat4 mat4_rotate_x(float angle);
Mat4 mat4_rotate_y(float angle);
Mat4 mat4_rotate_z(float angle);
Vec4 mat4_mul_vec4(Mat4 m, Vec4 v);
Vec4 vec3_to_vec4(Vec3 A);


ProjectedVertex project(Vec3 point, float fov);

Vec2 ndc_to_screen(Vec2 ndc);

void getBaricentric(Vec2 A, Vec2 B, Vec2 C, Vec2 p, float* l1, float* l2, float* l3);

Vec2 getInfiniteLineIntersectionPoint(Vec2 Line1Point1, Vec2 Line1Point2, Vec2 Line2Point1, Vec2 Line2Point2);

int getSegmentLineIntersectionPoint(Vec2 Line1Point1, Vec2 Line1Point2, Vec2 Line2Point1, Vec2 Line2Point2, Vec2* out);

/**
 * All vectors should follow clockwise direction  
 * @return a (non-normalized) normal of two vector3 starting from vector A. 
 * @param A is the Vector 0 (or the start position) of the two other vectors.
 * @param B is the Vector 1 of the figure 
 * @param C is the vector 2 of the figure 
 */
Vec3 getNormalVec3(Vec3 A, Vec3 B, Vec3 C);

/**
 * All vectors should follow clockwise direction  
 * @return a normalized (0-1) normal of two vector3 starting from vector A. 
 * @param A is the Vector 0 (or the start position) of the two other vectors.
 * @param B is the Vector 1 of the figure 
 * @param C is the vector 2 of the figure 
 */
Vec3 getNormalizedNormalVec3(Vec3 A, Vec3 B, Vec3 C);

/**
 * This function takes in 3 vertices and returns which way do they face. 
 * It is crucial to put them in clockwise order. 
 * @return a facing value of the specific face (triangle)
 * @param A Is the 1st vertex of the cube
 * @param B is the 2nd vertex of the cube
 * @param C is the 3rd vertex of the cube
 */
float getFacing(Vec3 A, Vec3 B, Vec3 C);

/**
 * @return A 3D point of the centre of gravity an array of points
 * @param A* takes an array of Vec3 to determine their centre of gravity/mass
 * @param n  takes the count of Vec3 points of the Arr \A
 */
Vec3 getCentreMass(Vec3* A, int n);
