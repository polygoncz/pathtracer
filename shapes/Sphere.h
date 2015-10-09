//
// Created by pavel on 15.9.15.
//

#ifndef PATHTRACER_SPHERE_H
#define PATHTRACER_SPHERE_H

#include <core/Primitive.h>
namespace pathtracer
{

class Sphere : public GeometricPrimitive
{
public:
    Sphere(const Vec3f& center, float radius);
    virtual ~Sphere();

    virtual bool intersect(const Ray &ray, Intersection &inter);
    virtual bool intersectP(const Ray &ray);
    virtual bool canIntersect() const;
    virtual void refine(std::vector<std::shared_ptr<Primitive> > &refined);
    virtual BBox bounds() const;
private:
    Vec3f c;
    float r;
};

}

#endif //PATHTRACER_SPHERE_H
