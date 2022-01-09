#include "vector3.hpp"

vec3::vec3(float _x, float _y, float _z) {
    x = _x;
    y = _y;
    z = _z;
}

vec3::~vec3() {
    
}

vec3 vec3::operator+(vec3 operand) {
    return vec3(x + operand.x, y + operand.y, z + operand.z);
}

vec3 vec3::operator-(vec3 operand) {
    return vec3(x - operand.x, y - operand.y, z - operand.z);
}

vec3 vec3::operator-() {
    return vec3(-x, -y, -z);
}

vec3 vec3::operator*(vec3 operand) {
    return vec3(x * operand.x, y * operand.y, z * operand.z);
}

vec3 vec3::operator*(float operand) {
    return vec3(x * operand, y * operand, z * operand);
}

vec3 vec3::operator/(vec3 operand) {
    return vec3(x / operand.x, y / operand.y, z / operand.z);
}

vec3 vec3::operator/(float operand) {
    return vec3(x / operand, y / operand, z / operand);
}

float vec3::dot(vec3 operand) {
    return ((x * operand.x) + (y * operand.y) + (z * operand.z));
}

vec3 vec3::cross(vec3 operand) {
    return vec3(
        (y * operand.z - z * operand.y),
        (z * operand.x - x * operand.z),
        (x * operand.y - y * operand.x)
        );
}

float vec3::magnitude() {
    return sqrt(x * x + y * y + z * z);
}

vec3 vec3::unit(){
    return vec3(x, y, z) / magnitude();
}