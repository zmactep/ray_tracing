#ifndef __CAMERA_H__
#define __CAMERA_H__

#include "vector.h"
#include "ray.h"

class Camera
{
private:
    Vector m_location;
    Vector m_direction;
    Vector m_up;
    Vector m_right;

    int m_mx, m_my;

    float m_wp, m_hp;

    float m_distance;

public:
    Camera();
    Camera( Vector location, Vector lookAt, Vector up,
            int mx, int my, float wp, float hp, float distance);

    void move( Vector location, Vector lookAt, Vector up );
    void apply( Ray &ray, int i, int j );

    int width();
    int height();
};

#endif//__CAMERA_H__
