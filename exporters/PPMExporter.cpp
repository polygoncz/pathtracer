//
// Created by pavel on 14.9.15.
//

#include <fstream>
#include "PPMExporter.h"

using namespace pathtracer;

PPMExporter::PPMExporter()
    : ImageExporter()
{

}
PPMExporter::~PPMExporter()
{

}

void PPMExporter::save(const char *path, Film *film, Filter *filter) const
{
    std::ofstream ofs;
    ofs.open(path);

    ofs << "P3" << std::endl;
    ofs << "# image produced with test pathtracer suite by Pavel Lokvenc" << std::endl;

    size_t w = film->width();
    size_t h = film->height();

    ofs << w << " " << h << std::endl;

    for (int y = 0; y < h; ++y)
    {
        for (int x = 0; x < w; ++x)
        {
            Vec3f c = filter->pixel(x, y, film);
            ofs << c[0] << " " << c[1] << " " << c[2];
            if (x < w - 1)
            {
                ofs << "  ";
            }
        }
        ofs << std::endl;
    }

    ofs.close();
}
