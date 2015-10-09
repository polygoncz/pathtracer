//
// Created by pavel on 14.9.15.
//

#ifndef PATHTRACER_PPMEXPORTER_H
#define PATHTRACER_PPMEXPORTER_H

#include "core/ImageExporter.h"

namespace pathtracer
{

class PPMExporter : public ImageExporter
{
public:
    PPMExporter();
    virtual ~PPMExporter();
    void save(const char *path, Film *film, Filter *filter) const override;
};

}


#endif //PATHTRACER_PPMEXPORTER_H
