#ifndef __SPHERE_H__
#define __SPHERE_H__

#include "vector.h"
#include "ray.h"

#include "setmaterial.h"
#include "material.h"

#include "shape.h"

class Sphere : public Shape
{
private:
    Vector m_center;
    float  m_radius;

public:
    Sphere();
    Sphere( const Vector &center, float radius,
            const Material &material = setMaterial(0) );

    float intersect( const Ray &ray ) const;
    Vector getNormal( const Vector &point ) const;
};

#endif//__SPHERE_H__
