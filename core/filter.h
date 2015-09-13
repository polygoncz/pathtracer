//
// Created by pavel on 1.8.15.
//

#ifndef PATHTRACER_FILTER_H
#define PATHTRACER_FILTER_H

#include "core/core.h"
#include "film.h"

namespace pathtracer
{

class Filter
{
public:
    Filter();
    Filter(Film* f);
    virtual ~Filter();

    virtual Vec3f pixel(int x, int y) const = 0;

    Film* film() const
    {
        return _film;
    }

    void setFilm(Film *film)
    {
        _film = film;
    }

protected:
    Film* _film;
};

}

#endif //PATHTRACER_FILTER_H
