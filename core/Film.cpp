#include "Film.h"

using namespace pathtracer;

Film::Film(size_t w, size_t h)
    : w(w),
      h(h)
{
    samples = new std::vector<Sample>[w * h];
}

Film::~Film()
{
    if (samples) delete[] samples;
}

void Film::addSample(float x, float y, Vec3f luminance)
{
    assert(0 <= x && x < w);
    assert(0 <= y && y < h);

    size_t pX = static_cast<size_t>(x);
    size_t pY = static_cast<size_t>(y);

    Sample s;
    s.x = x;
    s.y = y;
    s.luminance = luminance;

    samples[offset(pX, pY)].push_back(s);
}

std::vector<const Sample &> Film::getSamples(float x1, float y1, float x2, float y2)
{
    if (x1 > x2) std::swap(x1, x2);
    if (y1 > y2) std::swap(y1, y2);

    assert(0 <= x1 && x2 < w);
    assert(0 <= y1 && y2 < h);

    std::vector<const Sample &> ret;
    for (int x = (int) x1; x <= (int) x2; ++x)
        for (int y = (int) y1; y <= (int) y2; ++y)
        {
            const std::vector<Sample> &pixel = samples[offset(x, y)];
            for (const Sample &s : pixel)
            {
                if (x1 <= x && x < x2
                    && y1 <= y && y < y2)
                {
                    ret.push_back(s);
                }
            }
        }

    return ret;
}