//
// Created by pavel on 11.11.15.
//

#ifndef PATHTRACER_RAYTRACER_H
#define PATHTRACER_RAYTRACER_H

#include "Scene.h"
namespace pathtracer
{

class Renderer
{
public:
    Renderer(Scene* scene);
    virtual ~Renderer();

    virtual void render() const = 0;

private:
    Scene* scene;
    Film* film;
    Camera* camera;
};

}
#endif //PATHTRACER_RAYTRACER_H
