#include "Camera.h"

using namespace pathtracer;

Camera::Camera(const Vec3f &eye, const Vec3f &target, const Vec3f &up, float exposure)
    : eye(eye), target(target), up(up), exposure(exposure)
{
    computeUVW();
}

Camera::~Camera()
{ }

void Camera::computeUVW()
{
    w = eye - target;
    w.normalize();
    u = cross(up, w);
    u.normalize();
    v = cross(u, w);
    v.normalize();
}
Film* Camera::film() const
{
    return _film;
}
