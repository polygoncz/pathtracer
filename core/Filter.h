//
// Created by pavel on 1.8.15.
//

#ifndef PATHTRACER_FILTER_H
#define PATHTRACER_FILTER_H

#include "Core.h"
#include "Film.h"

namespace pathtracer
{

class Filter
{
public:
    Filter();
    virtual ~Filter();

    virtual Vec3f pixel(int x, int y, Film* film) const = 0;
};

}

#endif //PATHTRACER_FILTER_H
