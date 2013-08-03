#include "ray.h"

Ray::Ray()
{
    m_location = Vector(0);
    m_direction = Vector(0);
}

Ray::Ray( const Vector &location, const Vector &direction )
{
    m_location = location;

    m_direction = direction;
    m_direction.normalize();
}

//

Vector Ray::location_c() const
{
    return m_location;
}

Vector Ray::direction_c() const
{
    return m_direction;
}

Vector & Ray::location()
{
    return m_location;
}

Vector & Ray::direction()
{
    return m_direction;
}

//

Vector Ray::apply( float t ) const
{
    return (m_location + m_direction*t);
}
