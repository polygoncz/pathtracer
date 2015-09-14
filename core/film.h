#ifndef PATHTRACER_FILM_H
#define PATHTRACER_FILM_H

#include <stddef.h>
#include <vector>
#include <assert.h>
#include "core.h"

namespace pathtracer
{

class Film
{
public:
    struct Sample
    {
        float x, y;
        Vec3f luminance;
    };

    Film(size_t w, size_t h);
    ~Film();

    void addSample(float x, float y, Vec3f luminance);
    std::vector<const Sample&> getSamples(float x1, float y1, float x2, float y2);

    inline size_t width() const
    { return w; }

    inline size_t height() const
    { return h; }

private:
    inline size_t offset(size_t x, size_t y)
    {
        assert(0 <= x && x < w);
        assert(0 <= y && y < h);

        return x * h + y;
    }

    size_t w, h;
    std::vector<Sample>* samples;
};

}

#endif //PATHTRACER_FILM_H
