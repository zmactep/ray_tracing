#ifndef __PLANE_H__
#define __PLANE_H__

#include "vector.h"
#include "ray.h"

#include "setmaterial.h"
#include "material.h"

#include "shape.h"

class Plane : public Shape
{
private:
    Vector m_point;
    Vector m_normale;

public:
    Plane();
    Plane( const Vector &point, const Vector &normale,
           const Material &material = setMaterial(0) );

    float intersect( const Ray &ray ) const;
    Vector getNormal( const Vector &point ) const;
};

#endif//__PLANE_H__
