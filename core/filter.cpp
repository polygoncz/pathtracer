#include "core/filter.h"

using namespace pathtracer;

Filter::Filter()
    : _film(nullptr)
{

}

Filter::Filter(Film* f)
    : _film(f)
{

}

Filter::~Filter()
{

}
