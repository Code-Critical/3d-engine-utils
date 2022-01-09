#ifndef QUATERNION_H
#define QUATERNION_H

#include <math.h>
#include "vector3/vector3.hpp"

class quat {
public:
    float w = 0.0;
    vec3 v = vec3(0, 0, 0);
public:
    quat(float, vec3);
    ~quat();

    quat operator*(quat);

    quat conj();
};

#endif