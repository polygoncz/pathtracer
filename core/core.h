//
// Created by pavel on 27.7.15.
//

#ifndef PATHTRACER_CORE_H
#define PATHTRACER_CORE_H

namespace pathtracer
{

constexpr float EPSILON = 0.00001f;
constexpr float INF = std::numeric_limits<float>::infinity();

template<class T>
inline T clamp(T val, T from, T to)
{
    if (val < from) return from;
    if (val > to) return to;

    return val;
}

template<class T>
inline T min(const T& t1, const T& t2)
{
    return std::min(t1, t2);
}

template<class T>
inline T max(const T& t1, const T& t2)
{
    return std::max(t1, t2);
}

template<class T>
inline void swap(T& a, T& b)
{
    std::swap(a, b);
}

inline float lerp(const float t, const float a, const float b)
{
    return (1.f - t) * a + t * b;
}

inline bool quadratic(float a, float b, float c, float* t0, float* t1)
{
    float disc = b * b - 4 * a * c;

    if (disc < 0.f) return false;

    float e = std::sqrt(disc);
    float invLowerPart = 1.f / (2.f * a);

    if (t0) *t0 = (-b + e) * invLowerPart;
    if (t1) *t1 = (-b - e) * invLowerPart;

    return true;
}

inline int round2Int(Real f)
{
    return static_cast<int>(f + 0.5f);
}

class Vec3f
{
public:
    Vec3f()
        : x(0.f), y(0.f), z(0.f)
    { }

    Vec3f(float x, float y, float z)
        : x(x), y(y), z(z)
    { }

    Vec3f(const Vec3f& v)
        : x(v.x), y(v.y), z(v.z)
    { }

    ~Vec3f()
    { }

    float length() const
    {
        return std::sqrt(x * x + y * y + z * z);
    }

    float squarredLegth() const
    {
        return x * x + y * y + z * z;
    }

    Vec3f normalize()
    {
        float lengthInv = 1.f / length();

        x *= lengthInv;
        y *= lengthInv;
        z *= lengthInv;

        return *this;
    }

    Vec3f pow(float p)
    {
        x = std::pow(x, p);
        y = std::pow(y, p);
        z = std::pow(z, p);

        return *this;
    }

    const Vec3f& operator+() const
    {
        return *this;
    }

    const Vec3f& operator-() const
    {
        return Vec3f(-x, -y, -z);
    }

    bool operator==(const Vec3f& v) const
    {
        return x == v.x && y == v.y && z == v.z;
    }

    bool operator!=(const Vec3f& v) const
    {
        return x != v.x || y != v.y || z != v.z;
    }

    Vec3f operator+(const Vec3f& v) const
    {
        return Vec3f(x + v.x, y + v.y, z + v.z);
    }

    Vec3f operator+(const float a) const
    {
        return Vec3f(x + a, y + a, z + a);
    }

    Vec3f operator+=(const Vec3f& v)
    {
        *this = *this + v;
        return *this;
    }

    Vec3f operator+=(const float a)
    {
        *this = *this + a;
        return *this;
    }

    Vec3f operator-(const Vec3f& v) const
    {
        return Vec3f(x - v.x, y - v.y, z - v.z);
    }

    Vec3f operator-(const float a) const
    {
        return Vec3f(x - a, y - a, z - a);
    }

    Vec3f operator-=(const Vec3f& v)
    {
        *this = *this - v;
        return *this;
    }

    Vec3f operator-=(const float a)
    {
        *this = *this - a;
        return *this;
    }

    Vec3f operator/(float k) const
    {
        assert(k != 0.f);
        float invK = 1.f / k;
        return Vec3f(x * invK, y * invK, z * invK);
    }

    Vec3f& operator/=(float k)
    {
        assert(k != 0.f);
        float invK = 1.f / k;
        x *= invK;
        y *= invK;
        z *= invK;

        return *this;
    }

    Vec3f operator*(float k) const
    {
        return Vec3f(x * k, y * k, z * k);
    }

    friend Vec3f operator*(float k, const Vec3f& v);

    Vec3f& operator*=(float k)
    {
        x *= k;
        y *= k;
        z *= k;
        return *this;
    }

    Vec3f& operator=(const Vec3f& v)
    {
        if (&v == this)
            return *this;

        x = v.x;
        y = v.y;
        z = v.z;

        return *this;
    }

    float operator[](int i) const
    {
        assert(i >= 0 && i <= 2);
        return (&x)[i];
    }

    float& operator[](int i)
    {
        assert(i >= 0 && i <= 2);
        return (&x)[i];
    }

    float x, y, z;
};

Vec3f operator*(float k, const Vec3f& v)
{
    return Vec3f(v.x * k, v.y * k, v.z * k);
}

}

#endif //PATHTRACER_CORE_H
