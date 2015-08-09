//
// Created by pavel on 27.7.15.
//

#ifndef PATHTRACER_GEOMETRY_H
#define PATHTRACER_GEOMETRY_H

#include <stddef.h>
#include <cmath>
#include <assert.h>
#include <limits>

#include "core.h"

namespace pathtracer
{

class Ray
{
public:


    Ray()
        : mint(0.f),
          maxt(INF),
          epsilon(EPSILON),
          depth(0)
    { }

    Ray(const Vec3f& o, const Vec3f& d, float mint = 0.f, float maxt = INF, float epsilon = EPSILON, int depth = 0)
        : o(o), d(d), mint(mint),
          maxt(maxt),
          epsilon(epsilon),
          depth(depth)
    { }

    Vec3f operator()(float t) const
    {
        return o + d * t;
    }

    Vec3f o;
    Vec3f d;
    float mint, maxt;
    float epsilon;
    int depth;
};

class BBox
{
public:
    BBox()
    {
        pMin = Vec3f(INF, INF, INF);
        pMax = Vec3f(-INF, -INF, -INF);
    }

    BBox(const Vec3f& p)
        : pMin(p), pMax(p)
    { }

    BBox(const Vec3f& p1, const Vec3f& p2)
    {
        pMin = Vec3f(min(p1.x, p2.x), min(p1.y, p2.y), min(p1.z, p2.z));
        pMax = Vec3f(max(p1.x, p2.x), max(p1.y, p2.y), max(p1.z, p2.z));
    }

    BBox(const BBox& bb)
        : pMin(bb.pMin), pMax(bb.pMax)
    { }

    bool isInside(const Vec3f& p) const
    {
        return (p.x >= pMin.x && p.x <= pMax.x &&
                p.y >= pMin.y && p.y <= pMax.y &&
                p.z >= pMin.z && p.z <= pMax.z);
    }

    bool isOverlaps(const BBox& b) const
    {
        bool x = (pMax.x >= b.pMin.x && pMin.x <= b.pMax.x);
        bool y = (pMax.y >= b.pMin.y && pMin.y <= b.pMax.y);
        bool z = (pMax.z >= b.pMin.z && pMin.z <= b.pMax.z);
        return (x && y && z);
    }

    Vec3f diagonal() const
    {
        return pMax - pMin;
    }

    int maxDimensionIndex() const
    {
        Vec3f diag = diagonal();
        if (diag.x > diag.y && diag.x > diag.z)
            return 0;
        else if (diag.y > diag.z)
            return 1;
        else
            return 2;
    }

    Vec3f centroid() const
    {
        return (pMin + pMax) / 2.f;
    }

    Vec3f lerp(float tx, float ty, float tz) const
    {
        return Vec3f(pathtracer::lerp(tx, pMin.x, pMax.x),
                     pathtracer::lerp(ty, pMin.y, pMax.y),
                     pathtracer::lerp(tz, pMin.z, pMax.z));
    }

    Vec3f operator[](int i) const
    {
        assert(i >= 0 && i <= 1);
        return (&pMin)[i];
    }

    Vec3f& operator[](int i)
    {
        assert(i >= 0 && i <= 2);
        return (&pMin)[i];
    }

    Vec3f pMin;
    Vec3f pMax;
};

}
#endif //PATHTRACER_GEOMETRY_H
