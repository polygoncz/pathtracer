//
// Created by pavel on 1.8.15.
//

#ifndef PATHTRACER_IMAGEEXPORTER_H
#define PATHTRACER_IMAGEEXPORTER_H

#include "Film.h"
#include "Filter.h"

namespace pathtracer
{

class ImageExporter
{
public:
    ImageExporter();
    virtual ~ImageExporter();

    virtual void save(const char *path, Film* film, Filter* filter) const = 0;
};

}

#endif //PATHTRACER_IMAGEEXPORTER_H
