#include "SimpleFilter.h"

using namespace pathtracer;

SimpleFilter::SimpleFilter()
{

}

Vec3f SimpleFilter::pixel(int x, int y, Film *film) const
{
    std::vector<const Film::Sample&> samples = film->getSamples(x, y, x + 1, y + 1);
    Vec3f l;
    for (auto sample : samples)
        l += sample.luminance;
    l /= samples.size();

    return l;
}
