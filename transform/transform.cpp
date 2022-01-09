#include "transform.hpp"

transform::transform(
    float x, float y, float z, 
    float r00, float r01, float r02,
    float r10, float r11, float r12,
    float r20, float r21, float r22) {    
        
    data.components.r00 = r00;
    data.components.r01 = r01;
    data.components.r02 = r02;

    data.components.r10 = r10;
    data.components.r11 = r11;
    data.components.r12 = r12;

    data.components.r20 = r20;
    data.components.r21 = r21;
    data.components.r22 = r22;

    data.components.x = x;
    data.components.y = y;
    data.components.z = z;
}

transform::transform(float angle, vec3 axis) {
    quat rot(cos(angle / 2), axis * sin(angle / 2));

    vec3 right = (rot * quat(0, rightVector()) * rot.conj()).v;
    data.components.r00 = right.x;
    data.components.r10 = right.y;
    data.components.r20 = right.z;

    vec3 up = (rot * quat(0, upVector()) * rot.conj()).v;
    data.components.r01 = up.x;
    data.components.r11 = up.y;
    data.components.r21 = up.z;

    vec3 front = (rot * quat(0, frontVector()) * rot.conj()).v;
    data.components.r02 = front.x;
    data.components.r12 = front.y;
    data.components.r22 = front.z;

    data.components.x = 0;
    data.components.y = 0;
    data.components.z = 0; 
}

transform::~transform() {

}

vec3 transform::position() {
    return vec3(data.components.x, data.components.y, data.components.z);
}

vec3 transform::rightVector() {
    return vec3(data.components.r00, data.components.r10, data.components.r20);
}

vec3 transform::upVector() {
    return vec3(data.components.r01, data.components.r11, data.components.r21);
}

vec3 transform::frontVector() {
    return -vec3(data.components.r02, data.components.r12, data.components.r22);
}

transform transform::operator* (transform operand) {
    transform result(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

    for (int row = 0; row < 4; row++) {
        for (int column = 0; column < 4; column++) {
            result.data.matrix[row * 4 + column] = 0;
            for (int element = 0; element < 4; element++) {
                result.data.matrix[row * 4 + column] += 
                    data.matrix[row * 4 + element] * 
                    operand.data.matrix[element * 4 + column];
            }
        }
    }

    return result;
}

transform transform::operator*= (transform operand) {
    return *this * operand;
}

vec3 transform::operator* (vec3 operand) {
    vec3 result = position() + rightVector() * operand.x + 
        upVector() * operand.y - frontVector() * operand.z; 

    return result;
}

vec3 transform::operator*= (vec3 operand) {
    return *this * operand;
}

transform transform::operator+ (vec3 operand) {
    transform result(operand.x, operand.y, operand.z, 0, 0, 0, 0, 0, 0, 0, 0, 0);

    for (int row = 0; row < 4; row++) {
        for (int column = 0; column < 4; column++) {
            result.data.matrix[row * 4 + column] += data.matrix[row * 4 + column];
        }
    }

    return result;
}

transform transform::operator+= (vec3 operand) {
    return *this + operand;
}

transform transform::operator- (vec3 operand) {
    transform result(-operand.x, -operand.y, -operand.z, 0, 0, 0, 0, 0, 0, 0, 0, 0);

    for (int row = 0; row < 4; row++) {
        for (int column = 0; column < 4; column++) {
            result.data.matrix[row * 4 + column] += data.matrix[row * 4 + column];
        }
    }

    return result;
}

transform transform::operator-= (vec3 operand) {
    return *this - operand;
}