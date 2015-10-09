//
// Created by pavel on 15.9.15.
//

#ifndef PATHTRACER_PRIMITIVE_H
#define PATHTRACER_PRIMITIVE_H

#include <vector>
#include <memory>
#include "Intersection.h"
namespace pathtracer
{

class Primitive
{
public:
    Primitive();
    virtual ~Primitive();

    virtual bool intersect(const Ray& ray, Intersection& inter) = 0;
    virtual bool intersectP(const Ray& ray) = 0;
    virtual bool canIntersect() const = 0;
    virtual void refine(std::vector<std::shared_ptr<Primitive> >& refined) = 0;
    virtual BBox bounds() const = 0;
};

class GeometricPrimitive : public Primitive
{
public:
    GeometricPrimitive();
    virtual ~GeometricPrimitive();
};

class Aggregate : public Primitive
{
public:
    virtual bool canIntersect() const;
    virtual void refine(std::vector<std::shared_ptr<Primitive> > &refined);
};

}

#endif //PATHTRACER_PRIMITIVE_H
