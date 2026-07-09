#include <math.h>
#include <stdio.h>

#include "mathD.h"
#include "logger.h"
#include "global.h"

float vec2_dot(Vec2 A, Vec2 B){
    return (A.x * B.x)+ (A.y*B.y);
}

float vec2_cross(Vec2 A, Vec2 B){
    return (A.x*B.y) - (A.y*B.x);
}

Vec2 vec2_scalar(Vec2 A, float scalar){
    return (Vec2){A.x*scalar, A.y*scalar}; 
}

Vec2 vec2_add(Vec2 A, Vec2 B){
    return (Vec2){A.x+B.x, A.y+B.y};
}

Vec2 vec2_minus(Vec2 A, Vec2 B){
    return (Vec2){A.x-B.x, A.y-B.y};
}

Vec2 vec2_normalize(Vec2 A){
    float length = vec2_length(A);
    if(length< EPSILON) return (Vec2){0,0};
    return (Vec2){A.x/length, A.y/length};
}

float vec2_length(Vec2 A){
    return sqrt((A.x * A.x)+ (A.y * A.y));
}
float vec2_length_sq(Vec2 A){
    return (A.x * A.x)+ (A.y * A.y);
}


float vec3_dot(Vec3 A, Vec3 B){
    return (A.x * B.x) + (A.y*B.y)+ (A.z * B.z);
}
Vec3 vec3_cross(Vec3 A, Vec3 B){
    return (Vec3){
        (A.y*B.z) - (A.z*B.y),
       -(A.x*B.z) + (A.z*B.x),
        (A.x*B.y) - (A.y*B.x)
    };
}
Vec3 vec3_scalar(Vec3 A, float scalar){
    return (Vec3){A.x*scalar, A.y*scalar, A.z*scalar};
}
Vec3 vec3_add(Vec3 A, Vec3 B){
    return (Vec3){A.x+B.x, A.y+B.y, A.z+B.z};
}
Vec3 vec3_minus(Vec3 A, Vec3 B){
    return (Vec3){A.x-B.x, A.y-B.y, A.z-B.z};
}
Vec3 vec3_normalize(Vec3 A){
    float length = vec3_length(A);
    if(length< EPSILON) return (Vec3){0,0,0};
    return (Vec3){A.x/length, A.y/length, A.z/length};
}
float vec3_length(Vec3 A){
    return sqrt((A.x * A.x)+ (A.y * A.y) + (A.z*A.z));
}
float vec3_length_sq(Vec3 A){
    return (A.x * A.x)+ (A.y * A.y) + (A.z*A.z);
}
Vec4 vec3_to_vec4(Vec3 A){
    return (Vec4){A.x,A.y,A.z,1};
}




float vec4_dot(Vec4 A, Vec4 B){
    return (A.x * B.x) + (A.y* B.y)+ (A.z * B.z) + (A.w * B.w);
}
Vec4 vec4_scalar(Vec4 A, float scalar){
    return (Vec4){A.x*scalar, A.y*scalar, A.z*scalar, A.w*scalar};
}
Vec4 vec4_add(Vec4 A, Vec4 B){
    return (Vec4){A.x+B.x, A.y+B.y, A.z+B.z, A.w+B.w};
}
Vec4 vec4_minus(Vec4 A, Vec4 B){
    return (Vec4){A.x-B.x, A.y-B.y, A.z-B.z, A.w-B.w};
}
Vec4 vec4_normalize(Vec4 A){

    float length = vec4_length(A);
    if(length< EPSILON) return (Vec4){0,0,0,0};
    return (Vec4){A.x/length, A.y/length, A.z/length,A.w/length};
}
float vec4_length(Vec4 A){
    
    return sqrt((A.x * A.x)+ (A.y * A.y) + (A.z*A.z) + (A.w*A.w));
}
float vec4_length_sq(Vec4 A){
    return (A.x * A.x)+ (A.y * A.y) + (A.z*A.z) + (A.w*A.w);
}

Mat4 mat4_identity(){
    return (Mat4){{
        {1,0,0,0},
        {0,1,0,0},
        {0,0,1,0},
        {0,0,0,1}
    }};
}

Mat4 mat4_multiply(Mat4 A, Mat4 B){
    Mat4 C;
    for(int i=0; i<4;i++){
        for(int j=0; j<4;j++){
            float sum=0; 
            for(int k=0;k<4;k++){
                sum+=(A.m[i][k] *B.m[k][j]);
            }
            C.m[i][j] = sum;
        }
    }
    return C;
}
Mat4 mat4_translate(float x, float y, float z){
    Mat4 m = mat4_identity();
    m.m[0][3] = x;
    m.m[1][3] = y;
    m.m[2][3] = z;
    return m;
}
Mat4 mat4_scale(float x, float y, float z){
    Mat4 m = mat4_identity();
    m.m[0][0] = x;
    m.m[1][1] = y;
    m.m[2][2] = z;
    return m;
}
Mat4 mat4_rotate_x(float angle){
    Mat4 m = mat4_identity();
    m.m[1][1] = cos(angle);
    m.m[1][2] = -sin(angle);
    m.m[2][1] = sin(angle);
    m.m[2][2] = cos(angle);
    return m;
}
Mat4 mat4_rotate_y(float angle){
    Mat4 m = mat4_identity();
    m.m[0][0] = cos(angle);
    m.m[0][2] = sin(angle);
    m.m[2][0] = -sin(angle);
    m.m[2][2] = cos(angle);
    return m;
}
Mat4 mat4_rotate_z(float angle){
    Mat4 m = mat4_identity();
    m.m[0][0] = cos(angle);
    m.m[1][1] = cos(angle);
    m.m[0][1] = -sin(angle);
    m.m[1][0] = sin(angle);
    return m;
}
Vec4 mat4_mul_vec4(Mat4 m, Vec4 v){
    return (Vec4){
        m.m[0][0]*v.x + m.m[0][1]*v.y + m.m[0][2]*v.z + m.m[0][3]*v.w,
        m.m[1][0]*v.x + m.m[1][1]*v.y + m.m[1][2]*v.z + m.m[1][3]*v.w,
        m.m[2][0]*v.x + m.m[2][1]*v.y + m.m[2][2]*v.z + m.m[2][3]*v.w,
        m.m[3][0]*v.x + m.m[3][1]*v.y + m.m[3][2]*v.z + m.m[3][3]*v.w,
    };
}

Vec3 vec4_to_vec3(Vec4 A){
    return(Vec3){
        A.x/A.w,
        A.y/A.w,
        A.z/A.w 
    };
}

Vec2 project(Vec3 point, float fov){
    // printf("\n");
    // logger_vec3(DEBUG, "Original vec3:\n x:%f, y:%f, z:%f", point);

    if(point.z <=0){
        // logger(WARNING, "point:{%f,%f,%f} is out of z bounds.", point.x, point.y, point.z);
        return (Vec2){point.x, point.y};
    }
    float f = 1/tan(DEG_TO_RAD(fov/2));
    Vec2 ndcPoint = {f*(point.x/point.z), f*(point.y/point.z)};
    
    if(ndcPoint.x <-1 || ndcPoint.x >1)
        logger(WARNING, "X is out of bounds: %f",ndcPoint.x );
    if(ndcPoint.y<-1 || ndcPoint.y >1)
        logger(WARNING, "Y is out of bounds: %f",ndcPoint.y );
        
    // logger_vec2(DEBUG, "projected NDC:\n x:%f, y:%f", ndcPoint);
    Vec2 screenPoint = ndc_to_screen(ndcPoint);
    // logger_vec2(DEBUG, "projected Screen points:\n x:%f, y:%f", screenPoint);
    return screenPoint;
}


Vec2 ndc_to_screen(Vec2 ndc){
    return (Vec2){
        ((ndc.x+1)/2) *SCREEN_WIDTH,
        ((ndc.y+1)/2 ) * SCREEN_HEIGHT
    };
}

void getBaricentric(Vec2 A, Vec2 B, Vec2 C,
    Vec2 p, 
    float* l1, float* l2, float* l3){
        *l1 = 
        (vec2_cross(vec2_minus(p,C), vec2_minus(B,C) ))/
        (vec2_cross(vec2_minus(A,C), vec2_minus(B,C)));
        *l2 = 
        (vec2_cross(vec2_minus(p,A), vec2_minus(C,A)))/
        (vec2_cross(vec2_minus(A,C),vec2_minus(B,C)));
        *l3 = 1 - *l2 - *l1;
    }
    //todo fix it to return int, and a pointer. 
Vec2 getInfiniteLineIntersectionPoint(Vec2 Line1Point1, Vec2 Line1Point2, Vec2 Line2Point1, Vec2 Line2Point2){

    Vec2 intersectionPoint;

    float x1 = Line1Point1.x;
    float x2 = Line1Point2.x;
    float x3 = Line2Point1.x;
    float x4 = Line2Point2.x;

    float y1 = Line1Point1.y;
    float y2 = Line1Point2.y;
    float y3 = Line2Point1.y;
    float y4 = Line2Point2.y;

    float det12   = x1*y2 - x2*y1; 
    float det34    = x3*y4 - x4*y3;

    float diffX1  = x1 - x2;
    float diffX2  = x3 - x4;
    float diffY1  = y1 - y2;
    float diffY2  = y3 - y4;

    float denominator = diffX1 * diffY2 - diffY1 * diffX2;

    float nominatorX = det12 * diffX2 - diffX1 * det34;
    float nominatorY = det12 * diffY2 - diffY1 * det34;

    if (fabsf(denominator) < 1e-6f) {
        return (Vec2){-9999,-9999};
    }

    intersectionPoint.x = nominatorX / denominator;
    intersectionPoint.y = nominatorY / denominator;

    return intersectionPoint;
}


int getSegmentLineIntersectionPoint(Vec2 Line1Point1, Vec2 Line1Point2, Vec2 Line2Point1, Vec2 Line2Point2, Vec2* out){
    Vec2 intersectionPoint;

    float x1 = Line1Point1.x;
    float x2 = Line1Point2.x;
    float x3 = Line2Point1.x;
    float x4 = Line2Point2.x;

    float y1 = Line1Point1.y;
    float y2 = Line1Point2.y;
    float y3 = Line2Point1.y;
    float y4 = Line2Point2.y;

    /*
    s(x2-x1) - t(x4-x3) = x3-x1
    s(y2-y1) - t(y4-y3) = y3-y1

    a*s + b*t = e
    c*s + d*t = f

    a = dX1;
    b = dX2;
    c = dY1;
    d = dY2;
    e = diffX;
    f = diffY;

    s = (e*d - b*f) / (a*d - b*c)
    t = (a*f - e*c) / (a*d - b*c)
    */

    float dX1 = x2-x1;
    float dX2 = -(x4-x3);
    float dY1 = y2-y1;
    float dY2 = -(y4-y3);

    float diffX = x3-x1;
    float diffY = y3-y1;

    float denom = dX1*dY2 - (dX2*dY1);

    if (fabsf(denom) < 1e-6f) {
        return 0;
    }
    float nominS = diffX * dY2 - (dX2 * diffY);
    float nominT = dX1 * diffY - (diffX * dY1);

    float s = nominS/denom;
    float t = nominT/denom;

    if(s<0 || s> 1 || t<0 || t>1){
        return 0; 
    }

    /*
    x0 = x1 + s(x2 - x1)
    y0 = y1 + s(y2 - y1)
*/

    float x0 =x1 + s*(x2-x1);
    float y0 =y1 + s*(y2-y1); 
    
    out->x = x0;
    out->y =y0;

    return 1;

}