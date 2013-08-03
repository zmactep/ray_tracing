#include "plane.h"

Plane::Plane()
{
    m_point = 0;
    m_normale = 0;
}

Plane::Plane( const Vector &point, const Vector &normale,
              const Material &material )
{
    m_point = point;
    m_normale = normale;
    m_material = material;
}

//

float Plane::intersect( const Ray &ray ) const
{
    float p = (m_point % m_normale);
    float x = (ray.direction_c() % m_normale);
    float t;

    if( x == 0 )
        return -1;

    t = (-(m_normale % ray.location_c()) + p) / x;

    if( t < EPS )
        return -1;

    return t;
}

Vector Plane::getNormal( const Vector &point ) const
{
    return m_normale;
}
