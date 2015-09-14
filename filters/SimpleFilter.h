#pragma once

#ifndef PATHTRACER_SIMPLEFILTER_H
#define PATHTRACER_SIMPLEFILTER_H

#include "core/filter.h"

namespace pathtracer
{

class SimpleFilter : public Filter
{
public:
    SimpleFilter();
    
    Vec3f pixel(int x, int y, Film *film) const override;
};

}

#endif //PATHTRACER_SIMPLEFILTER_H
