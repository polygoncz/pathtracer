//
// Created by pavel on 15.9.15.
//

#ifndef PATHTRACER_SCENE_H
#define PATHTRACER_SCENE_H

#include "Core.h"
#include "Film.h"
#include "Primitive.h"
#include "Camera.h"

namespace pathtracer
{

class Scene
{
public:
    Scene();
    ~Scene();

    bool intersect(const Ray& ray, Intersection& inter) const;
    bool intersectP(const Ray& ray) const;
    BBox bounds() const;


    Vec3f background() const;
    void setBackground(const Vec3f &background);

    Aggregate * aggregator() const;
    void setAggregator(Aggregate* aggregator);
private:
    Vec3f _background;
    Aggregate* _aggregator;
};

}


#endif //PATHTRACER_SCENE_H
