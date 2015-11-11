//
// Created by pavel on 9.10.15.
//

#include "Random.h"

using namespace pathtracer;

Random& Random::instance()
{
    static Random r;
    return r;
}

Random::Random()
{
    unsigned seed = 123456u;
    g.seed(seed);
}
