//
// Created by pavel on 15.9.15.
//

#ifndef PATHTRACER_CAMERA_H
#define PATHTRACER_CAMERA_H

#include "Core.h"
#include "Film.h"
#include "Geometry.h"
namespace pathtracer
{

struct CameraSample
{
    float x, y;
};

typedef CameraSample Pixel;

class Camera
{
public:
/**
	 * Konstruktor.
	 * @param eye bod pozorovatele
	 * @param target cíl pozorování
	 * @param up vektor natočení
	 * @param exposure expozice (FUTURE)
	 */
    Camera(const Vec3f& eye, const Vec3f& target, const Vec3f& up,
           float exposure = 1.f);

    /**
     * Virtuální destruktor.
     */
    virtual ~Camera();

    /**
     * Na základě zadaných parametrů v podobě vzorku na filmu kamery vypočítá
     * odpovídající transformovaný paprsek. Implementace je potom provedena
     * v potomcích třídy.
     * @param sample vzorek na filmu kamery
     * @param ray ukazatel na instanci třídy Ray, slouží jako návratová hodnota
     */
    virtual void generateRay(const CameraSample& sample, Ray* ray) const = 0;

protected:
    /**
     * Výpočet ortonormální báze pohledu.
     */
    void computeUVW();

protected:
    Film* film; ///< Ukazatel na film.
    Vec3f eye; ///< Bod pozorovatele.
    Vec3f target; ///< Bod cíle pozorování.
    Vec3f up; ///< Vektor natočení kamery.
    Vec3f u; ///< Vektor ortonormální báze pohledu
    Vec3f v; ///< Vektor ortonormální báze pohledu
    Vec3f w; ///< Vektor ortonormální báze pohledu
    float exposure; ///< expozice (FUTURE)
};

}

#endif //PATHTRACER_CAMERA_H
