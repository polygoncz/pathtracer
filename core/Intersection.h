//
// Created by pavel on 15.9.15.
//

#ifndef PATHTRACER_INTERSECTION_H
#define PATHTRACER_INTERSECTION_H

#include "Core.h"
#include "Geometry.h"

namespace pathtracer
{

struct Intersection
{
    Intersection()
        : hitObject(false), depth(0), t(INF)
    { }

    Intersection(const Intersection& inter)
        : hitObject(inter.hitObject),
          hitPoint(inter.hitPoint),
          normal(inter.normal),
          ray(inter.ray),
          depth(inter.depth),
          t(inter.t)
    { }

    bool hitObject;
    Vec3f hitPoint;
    Vec3f normal;
    Ray ray;
    int depth;
    float t;
};

}


#endif //PATHTRACER_INTERSECTION_H
