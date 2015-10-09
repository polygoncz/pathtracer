#include "Sphere.h"

using namespace pathtracer;

Sphere::Sphere(const Vec3f& center, float radius)
    : c(center), r(radius)
{ }

Sphere::~Sphere()
{ }

bool Sphere::intersect(const Ray &ray, Intersection &inter)
{
    Vec3f temp = ray.o - c;
    float a = dot(ray.d, ray.d);
    float b = 2 * dot(temp, ray.d);
    float c = dot(temp, temp) - r * r;

    float t1, t2;
    if (!quadratic(a, b, c, &t1, &t2))
    {
        return false;
    }
    else
    {
        float t = min(t1, t2);

        if (t > EPSILON && t < inter.t)
        {
            ray.epsilon = 1e-3f * t;
            inter.normal = (temp + ray.d * t) / r;
            inter.ray = ray;
            inter.t = t;
            inter.hitPoint = ray(t);
            inter.hitObject = true;
            return true;
        }
    }

    return false;
}

bool Sphere::intersectP(const Ray &ray)
{
    Vec3f temp = ray.o - c;
    float a = dot(ray.d, ray.d);
    float b = 2 * dot(temp, ray.d);
    float c = dot(temp, temp) - r * r;

    float t1, t2;
    if (!quadratic(a, b, c, &t1, &t2)) return false;

    float t = min(t1, t2);

    return t > EPSILON;
}

bool Sphere::canIntersect() const
{
    return true;
}

void Sphere::refine(std::vector<std::shared_ptr<Primitive> > &refined)
{
    return;
}

BBox Sphere::bounds() const
{
    return BBox({c[0] - r, c[1] - r, c[2] - r},
                {c[0] - r, c[1] - r, c[2] - r});
}


