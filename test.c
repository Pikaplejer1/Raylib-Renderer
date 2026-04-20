#include <math.h>
#include <stdio.h>
#include <assert.h>

#include "mathD.h"

#define FLOAT_EQ(a, b) (fabs((a) - (b)) < EPSILON)  // float comparison with tolerance

// ─── VEC2 ───────────────────────────────────────────────────────────────────

void test_vec2_dot(){
    Vec2 A = {1, 2};
    Vec2 B = {3, 4};
    float result = vec2_dot(A, B);
    printf("vec2_dot: %f (expected 11)\n", result);
    assert(FLOAT_EQ(result, 11.0f));
}

void test_vec2_cross(){
    Vec2 A = {1, 2};
    Vec2 B = {3, 4};
    float result = vec2_cross(A, B);
    printf("vec2_cross: %f (expected -2)\n", result);
    assert(FLOAT_EQ(result, -2.0f));
}

void test_vec2_scalar(){
    Vec2 A = {2, 3};
    Vec2 result = vec2_scalar(A, 2.0f);
    printf("vec2_scalar: {%f, %f} (expected {4, 6})\n", result.x, result.y);
    assert(FLOAT_EQ(result.x, 4.0f) && FLOAT_EQ(result.y, 6.0f));
}

void test_vec2_add(){
    Vec2 A = {1, 2};
    Vec2 B = {3, 4};
    Vec2 result = vec2_add(A, B);
    printf("vec2_add: {%f, %f} (expected {4, 6})\n", result.x, result.y);
    assert(FLOAT_EQ(result.x, 4.0f) && FLOAT_EQ(result.y, 6.0f));
}

void test_vec2_minus(){
    Vec2 A = {5, 7};
    Vec2 B = {2, 3};
    Vec2 result = vec2_minus(A, B);
    printf("vec2_minus: {%f, %f} (expected {3, 4})\n", result.x, result.y);
    assert(FLOAT_EQ(result.x, 3.0f) && FLOAT_EQ(result.y, 4.0f));
}

void test_vec2_length(){
    Vec2 A = {3, 4};
    float result = vec2_length(A);
    printf("vec2_length: %f (expected 5)\n", result);
    assert(FLOAT_EQ(result, 5.0f));
}

void test_vec2_length_sq(){
    Vec2 A = {3, 4};
    float result = vec2_length_sq(A);
    printf("vec2_length_sq: %f (expected 25)\n", result);
    assert(FLOAT_EQ(result, 25.0f));
}

void test_vec2_normalize(){
    Vec2 A = {3, 4};
    Vec2 result = vec2_normalize(A);
    printf("vec2_normalize: {%f, %f} (expected {0.6, 0.8})\n", result.x, result.y);
    assert(FLOAT_EQ(result.x, 0.6f) && FLOAT_EQ(result.y, 0.8f));
    // normalized vector length should always be 1
    assert(FLOAT_EQ(vec2_length(result), 1.0f));
}

// ─── VEC3 ───────────────────────────────────────────────────────────────────

void test_vec3_dot(){
    Vec3 A = {1, 2, 3};
    Vec3 B = {4, 5, 6};
    float result = vec3_dot(A, B);
    printf("vec3_dot: %f (expected 32)\n", result);
    assert(FLOAT_EQ(result, 32.0f));
}

void test_vec3_cross(){
    Vec3 A = {1, 2, 3};
    Vec3 B = {3, 4, 5};
    Vec3 result = vec3_cross(A, B);
    printf("vec3_cross: {%f, %f, %f} (expected {-2, 4, -2})\n", result.x, result.y, result.z);
    assert(FLOAT_EQ(result.x, -2.0f) && FLOAT_EQ(result.y, 4.0f) && FLOAT_EQ(result.z, -2.0f));
}

void test_vec3_scalar(){
    Vec3 A = {1, 2, 3};
    Vec3 result = vec3_scalar(A, 3.0f);
    printf("vec3_scalar: {%f, %f, %f} (expected {3, 6, 9})\n", result.x, result.y, result.z);
    assert(FLOAT_EQ(result.x, 3.0f) && FLOAT_EQ(result.y, 6.0f) && FLOAT_EQ(result.z, 9.0f));
}

void test_vec3_add(){
    Vec3 A = {1, 2, 3};
    Vec3 B = {4, 5, 6};
    Vec3 result = vec3_add(A, B);
    printf("vec3_add: {%f, %f, %f} (expected {5, 7, 9})\n", result.x, result.y, result.z);
    assert(FLOAT_EQ(result.x, 5.0f) && FLOAT_EQ(result.y, 7.0f) && FLOAT_EQ(result.z, 9.0f));
}

void test_vec3_minus(){
    Vec3 A = {5, 7, 9};
    Vec3 B = {1, 2, 3};
    Vec3 result = vec3_minus(A, B);
    printf("vec3_minus: {%f, %f, %f} (expected {4, 5, 6})\n", result.x, result.y, result.z);
    assert(FLOAT_EQ(result.x, 4.0f) && FLOAT_EQ(result.y, 5.0f) && FLOAT_EQ(result.z, 6.0f));
}

void test_vec3_length(){
    Vec3 A = {1, 2, 2};
    float result = vec3_length(A);
    printf("vec3_length: %f (expected 3)\n", result);
    assert(FLOAT_EQ(result, 3.0f));
}

void test_vec3_length_sq(){
    Vec3 A = {1, 2, 2};
    float result = vec3_length_sq(A);
    printf("vec3_length_sq: %f (expected 9)\n", result);
    assert(FLOAT_EQ(result, 9.0f));
}

void test_vec3_normalize(){
    Vec3 A = {1, 2, 2};
    Vec3 result = vec3_normalize(A);
    printf("vec3_normalize: {%f, %f, %f} (expected {0.333, 0.666, 0.666})\n", result.x, result.y, result.z);
    assert(FLOAT_EQ(vec3_length(result), 1.0f));
}

// ─── VEC4 ───────────────────────────────────────────────────────────────────

void test_vec4_dot(){
    Vec4 A = {1, 2, 3, 4};
    Vec4 B = {5, 6, 7, 8};
    float result = vec4_dot(A, B);
    printf("vec4_dot: %f (expected 70)\n", result);
    assert(FLOAT_EQ(result, 70.0f));
}

void test_vec4_scalar(){
    Vec4 A = {1, 2, 3, 4};
    Vec4 result = vec4_scalar(A, 2.0f);
    printf("vec4_scalar: {%f, %f, %f, %f} (expected {2, 4, 6, 8})\n", result.x, result.y, result.z, result.w);
    assert(FLOAT_EQ(result.x, 2.0f) && FLOAT_EQ(result.y, 4.0f) && FLOAT_EQ(result.z, 6.0f) && FLOAT_EQ(result.w, 8.0f));
}

void test_vec4_add(){
    Vec4 A = {1, 2, 3, 4};
    Vec4 B = {5, 6, 7, 8};
    Vec4 result = vec4_add(A, B);
    printf("vec4_add: {%f, %f, %f, %f} (expected {6, 8, 10, 12})\n", result.x, result.y, result.z, result.w);
    assert(FLOAT_EQ(result.x, 6.0f) && FLOAT_EQ(result.y, 8.0f) && FLOAT_EQ(result.z, 10.0f) && FLOAT_EQ(result.w, 12.0f));
}

void test_vec4_minus(){
    Vec4 A = {5, 6, 7, 8};
    Vec4 B = {1, 2, 3, 4};
    Vec4 result = vec4_minus(A, B);
    printf("vec4_minus: {%f, %f, %f, %f} (expected {4, 4, 4, 4})\n", result.x, result.y, result.z, result.w);
    assert(FLOAT_EQ(result.x, 4.0f) && FLOAT_EQ(result.y, 4.0f) && FLOAT_EQ(result.z, 4.0f) && FLOAT_EQ(result.w, 4.0f));
}

void test_vec4_length(){
    Vec4 A = {1, 2, 2, 0};
    float result = vec4_length(A);
    printf("vec4_length: %f (expected 3)\n", result);
    assert(FLOAT_EQ(result, 3.0f));
}

void test_vec4_length_sq(){
    Vec4 A = {1, 2, 2, 0};
    float result = vec4_length_sq(A);
    printf("vec4_length_sq: %f (expected 9)\n", result);
    assert(FLOAT_EQ(result, 9.0f));
}

void test_vec4_normalize(){
    Vec4 A = {1, 2, 2, 0};
    Vec4 result = vec4_normalize(A);
    printf("vec4_normalize: {%f, %f, %f, %f}\n", result.x, result.y, result.z, result.w);
    assert(FLOAT_EQ(vec4_length(result), 1.0f));
}
// helper — prints a mat4
void mat4_print(Mat4 m){
    for(int i=0;i<4;i++)
        printf("  [%6.2f %6.2f %6.2f %6.2f]\n", m.m[i][0], m.m[i][1], m.m[i][2], m.m[i][3]);
}

// helper — checks two mat4s are equal
int mat4_eq(Mat4 A, Mat4 B){
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            if(!FLOAT_EQ(A.m[i][j], B.m[i][j])) return 0;
    return 1;
}

void test_mat4_identity(){
    printf("mat4_identity:\n");
    Mat4 m = mat4_identity();
    mat4_print(m);
    // diagonal should be 1, everything else 0
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            assert(FLOAT_EQ(m.m[i][j], i==j ? 1.0f : 0.0f));
    printf("PASS\n\n");
}

void test_mat4_multiply(){
    printf("mat4_multiply:\n");
    // identity * identity = identity
    Mat4 I = mat4_identity();
    Mat4 result = mat4_multiply(I, I);
    mat4_print(result);
    assert(mat4_eq(result, I));

    // known multiplication
    Mat4 A = {{
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16}
    }};
    Mat4 B = {{
        {1,0,0,0},
        {0,1,0,0},
        {0,0,1,0},
        {0,0,0,1}
    }};
    // A * I should equal A
    result = mat4_multiply(A, B);
    assert(mat4_eq(result, A));
    printf("PASS\n\n");
}

void test_mat4_translate(){
    printf("mat4_translate:\n");
    Mat4 t = mat4_translate(3, 4, 5);
    mat4_print(t);
    assert(FLOAT_EQ(t.m[0][3], 3.0f));
    assert(FLOAT_EQ(t.m[1][3], 4.0f));
    assert(FLOAT_EQ(t.m[2][3], 5.0f));
    // rest of diagonal should still be identity
    assert(FLOAT_EQ(t.m[0][0], 1.0f));
    assert(FLOAT_EQ(t.m[1][1], 1.0f));
    assert(FLOAT_EQ(t.m[2][2], 1.0f));
    assert(FLOAT_EQ(t.m[3][3], 1.0f));
    printf("PASS\n\n");
}

void test_mat4_scale(){
    printf("mat4_scale:\n");
    Mat4 s = mat4_scale(2, 3, 4);
    mat4_print(s);
    assert(FLOAT_EQ(s.m[0][0], 2.0f));
    assert(FLOAT_EQ(s.m[1][1], 3.0f));
    assert(FLOAT_EQ(s.m[2][2], 4.0f));
    assert(FLOAT_EQ(s.m[3][3], 1.0f));
    printf("PASS\n\n");
}

void test_mat4_rotate_x(){
    printf("mat4_rotate_x:\n");
    // rotate by 0 should give identity
    Mat4 m = mat4_rotate_x(0.0f);
    mat4_print(m);
    assert(mat4_eq(m, mat4_identity()));

    // rotate by 90 degrees
    m = mat4_rotate_x(M_PI / 2.0f);
    mat4_print(m);
    assert(FLOAT_EQ(m.m[1][1],  0.0f));
    assert(FLOAT_EQ(m.m[1][2], -1.0f));
    assert(FLOAT_EQ(m.m[2][1],  1.0f));
    assert(FLOAT_EQ(m.m[2][2],  0.0f));
    printf("PASS\n\n");
}

void test_mat4_rotate_y(){
    printf("mat4_rotate_y:\n");
    Mat4 m = mat4_rotate_y(0.0f);
    assert(mat4_eq(m, mat4_identity()));

    m = mat4_rotate_y(M_PI / 2.0f);
    mat4_print(m);
    assert(FLOAT_EQ(m.m[0][0],  0.0f));
    assert(FLOAT_EQ(m.m[0][2],  1.0f));
    assert(FLOAT_EQ(m.m[2][0], -1.0f));
    assert(FLOAT_EQ(m.m[2][2],  0.0f));
    printf("PASS\n\n");
}

void test_mat4_rotate_z(){
    printf("mat4_rotate_z:\n");
    Mat4 m = mat4_rotate_z(0.0f);
    assert(mat4_eq(m, mat4_identity()));

    m = mat4_rotate_z(M_PI / 2.0f);
    mat4_print(m);
    assert(FLOAT_EQ(m.m[0][0],  0.0f));
    assert(FLOAT_EQ(m.m[0][1], -1.0f));
    assert(FLOAT_EQ(m.m[1][0],  1.0f));
    assert(FLOAT_EQ(m.m[1][1],  0.0f));
    printf("PASS\n\n");
}

void test_mat4_mul_vec4(){
    printf("mat4_mul_vec4:\n");
    // identity * v = v
    Mat4 I = mat4_identity();
    Vec4 v = {1, 2, 3, 4};
    Vec4 result = mat4_mul_vec4(I, v);
    printf("  result: {%f, %f, %f, %f} (expected {1, 2, 3, 4})\n", result.x, result.y, result.z, result.w);
    assert(FLOAT_EQ(result.x, 1.0f) && FLOAT_EQ(result.y, 2.0f) && FLOAT_EQ(result.z, 3.0f) && FLOAT_EQ(result.w, 4.0f));

    // translate matrix applied to a point
    Mat4 t = mat4_translate(1, 2, 3);
    Vec4 point = {0, 0, 0, 1};  // w=1 means point (not direction)
    result = mat4_mul_vec4(t, point);
    printf("  translated: {%f, %f, %f, %f} (expected {1, 2, 3, 1})\n", result.x, result.y, result.z, result.w);
    assert(FLOAT_EQ(result.x, 1.0f) && FLOAT_EQ(result.y, 2.0f) && FLOAT_EQ(result.z, 3.0f));
    printf("PASS\n\n");
}

// ─── MAIN ───────────────────────────────────────────────────────────────────

int main(){
    printf("=== VEC2 ===\n");
    test_vec2_dot();
    test_vec2_cross();
    test_vec2_scalar();
    test_vec2_add();
    test_vec2_minus();
    test_vec2_length();
    test_vec2_length_sq();
    test_vec2_normalize();

    printf("\n=== VEC3 ===\n");
    test_vec3_dot();
    test_vec3_cross();
    test_vec3_scalar();
    test_vec3_add();
    test_vec3_minus();
    test_vec3_length();
    test_vec3_length_sq();
    test_vec3_normalize();

    printf("\n=== VEC4 ===\n");
    test_vec4_dot();
    test_vec4_scalar();
    test_vec4_add();
    test_vec4_minus();
    test_vec4_length();
    test_vec4_length_sq();
    test_vec4_normalize();

    printf("=== MAT4 ===\n\n");
    test_mat4_identity();
    test_mat4_multiply();
    test_mat4_translate();
    test_mat4_scale();
    test_mat4_rotate_x();
    test_mat4_rotate_y();
    test_mat4_rotate_z();
    test_mat4_mul_vec4();
    printf("\nAll tests passed!\n");
    return 0;
}