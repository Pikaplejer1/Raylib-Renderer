#pragma once

#define EPSILON 0.0001f
#define M_PI 3.1415926535f
typedef struct  {float x,y;} Vec2;

typedef struct  {float x,y,z;} Vec3;

typedef struct  {float x,y,z,w;} Vec4;
typedef struct 
{
    float m[4][4];
} Mat4;


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


Vec2 project(Vec3 point, float fov);