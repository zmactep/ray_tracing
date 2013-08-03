#include "sphere.h"
#include <math.h>

#define sqr(x) (x)*(x)

Sphere::Sphere()
{
    m_center = 0;
    m_radius = 0;
}

Sphere::Sphere( const Vector &center, float radius, const Material &material )
{
    m_center = center;
    m_radius = radius;
    m_material = material;
}

//

float Sphere::intersect( const Ray &ray ) const
{
    Vector lc = ray.location_c() - m_center;
    
    float p = lc % ray.direction_c();
    float q = (lc % lc) - sqr(m_radius);
    float d = p * p - q;
    float t1, t2;

    if(d < 0)
        return -1;

    d = sqrt(d);
    t1 = -p + d;
    t2 = -p - d;

    if( t1 < 0 )
        return -1;
    
    if( t2 > 0 )
        return t2;
    
    return t1;
}

Vector Sphere::getNormal( const Vector &point ) const
{
    return (point - m_center) / m_radius;
}

#undef sqr
