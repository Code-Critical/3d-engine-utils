#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "vector3/vector3.hpp"
#include "quaternion/quaternion.hpp"

class transform {
public: // private:
    union __transformData {
        float matrix[16] = {
            1, 0, 0, 0,
            0, 1, 0, 0,
            0, 0, 1, 0,
            0, 0, 0, 1
        };
        struct {
            float r00; float r01; float r02; float x;
            float r10; float r11; float r12; float y;
            float r20; float r21; float r22; float z;
        } components;
    } data;
public:
    transform(
        float x = 0, float y = 0, float z = 0, 
        float r00 = 1, float r01 = 0, float r02 = 0,
        float r10 = 0, float r11 = 1, float r12 = 0,
        float r20 = 0, float r21 = 0, float r22 = 1);

    transform(float angle, vec3 axis);

    ~transform();

    vec3 position();

    vec3 frontVector();
    vec3 rightVector();
    vec3 upVector();

    transform operator* (transform operand);
    transform operator*= (transform operand);
    
    vec3 operator* (vec3 operand);
    vec3 operator*= (vec3 operand);

    transform operator+ (vec3 operand);
    transform operator+= (vec3 operand);

    transform operator- (vec3 operand);
    transform operator-= (vec3 operand);

};

#endif