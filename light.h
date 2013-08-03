#ifndef __LIGHT_H__
#define __LIGHT_H__

#include "vector.h"
#include "color.h"

class Light
{
protected:
    Color m_color;

public:
    virtual float shade( Vector &v, const Vector &point, const Vector &normale ) = 0;

    Color & color();
    Color color_c() const;
};

#endif//__LIGHT_H__
