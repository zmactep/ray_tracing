#ifndef __SHAPE_H__
#define __SHAPE_H__

#include "vector.h"
#include "ray.h"
#include "material.h"

class Shape
{
protected:
    Material m_material;

public:
    virtual float intersect( const Ray &ray ) const = 0;
    virtual Vector getNormal( const Vector &point ) const = 0;

    Material & material();
    Material material_c() const;
};

#endif//__SHAPE_H__
