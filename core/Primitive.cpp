//
// Created by pavel on 15.9.15.
//

#include "Primitive.h"

using namespace pathtracer;

Primitive::Primitive()
{

}
Primitive::~Primitive()
{

}
bool Aggregate::canIntersect() const
{
    return false;
}
void Aggregate::refine(std::vector<std::shared_ptr<Primitive> > &refined)
{
    return;
}
GeometricPrimitive::GeometricPrimitive()
{

}
GeometricPrimitive::~GeometricPrimitive()
{

}
