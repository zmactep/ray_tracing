#ifndef __POINT_LIGHT_H__
#define __POINT_LIGHT_H__

#include "setmaterial.h"

#include "vector.h"
#include "color.h"

#include "light.h"

class PointLight : public Light
{
private:
    Vector m_location;

public:
    PointLight();
    PointLight( const Vector &location, const Color &color = Color::white() );

    float shade( Vector &v, const Vector &point, const Vector &normale );
};

#endif//__POINT_LIGHT_H__
