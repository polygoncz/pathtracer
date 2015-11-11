#include "Renderer.h"
using namespace pathtracer;

Renderer::Renderer(Scene *scene)
    : scene(scene)
{
    camera = scene->camera();
    film = camera->film();
}

Renderer::~Renderer()
{

}
