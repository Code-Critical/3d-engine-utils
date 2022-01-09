#ifndef VECTOR3_H
#define VECTOR3_H

#include <math.h>

class vec3 {
public:
    float x, y, z;
public:
    vec3(float _x = 0, float _y = 0, float _z = 0);
    ~vec3();

    vec3 operator+(vec3);
    vec3 operator-(vec3);
    vec3 operator-();

    vec3 operator*(vec3);
    vec3 operator*(float);

    vec3 operator/(vec3);
    vec3 operator/(float);

    float dot(vec3);
    vec3 cross(vec3);

    float magnitude();
    vec3 unit();
};

#endif