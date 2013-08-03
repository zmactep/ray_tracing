#ifndef __RAY_H__
#define __RAY_H__

#include "vector.h"

class Ray
{
private:
    Vector m_location;
    Vector m_direction;

public:
    Ray();
    Ray( const Vector &location, const Vector &direction );

    Vector & location();
    Vector & direction();

    Vector location_c() const;
    Vector direction_c() const;

    Vector apply( float t ) const;
};

#endif//__RAY_H__
