//
// Created by pavel on 15.9.15.
//

#include "Scene.h"

using namespace pathtracer;

Scene::Scene()
{

}

Scene::~Scene()
{

}

bool Scene::intersect(const Ray &ray, Intersection &inter) const
{
    return _aggregator->intersect(ray, inter);
}

bool Scene::intersectP(const Ray &ray) const
{
    return _aggregator->intersectP(ray);
}

BBox Scene::bounds() const
{
    return _aggregator->bounds();
}

Vec3f Scene::background() const
{
    return _background;
}

void Scene::setBackground(const Vec3f &background)
{
    _background = background;
}

Aggregate *Scene::aggregator() const
{
    return _aggregator;
}

void Scene::setAggregator(Aggregate* aggregator)
{
    _aggregator = aggregator;
}