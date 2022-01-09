#include "quaternion.hpp"

quat::quat(float _w, vec3 _v) {
    w = _w;
    v = _v;
}

quat::~quat() {

}

quat quat::operator*(quat q) {
    return quat(w * q.w - v.dot(q.v), v.cross(q.v) + (v * q.w) + (q.v * w));
}

quat quat::conj() {
    return quat(w, -v);
}