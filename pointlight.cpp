#include "pointlight.h"

PointLight::PointLight()
{
    m_location = 0;
    m_color = 1;
}

PointLight::PointLight( const Vector &location, const Color &color )
{
    m_location = location;
    m_color = color;
}

float PointLight::shade( Vector &v, const Vector &point, const Vector &normale )
{
    Vector l;
    float lc;

    v = m_location - point;
    l = v.normale();

    lc = normale % l;

    if( lc < 0 )
        return 0;
    if( lc > 1 )
        return 1;

    return lc;
}
