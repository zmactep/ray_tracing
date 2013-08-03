#ifndef __SCENE_H__
#define __SCENE_H__

#include <cstdio>
#include <vector>

#include "vector.h"
#include "ray.h"

#include "color.h"
#include "material.h"
#include "setmaterial.h"

#include "shape.h"
#include "light.h"

#include "camera.h"

class Scene
{
private:
    Camera m_camera;

    std::vector<Shape*> m_shapes;
    std::vector<Light*> m_lights;

    int m_reflectionLevel;
    int m_reflectionMaxLevel;

    Color m_ambient;

public:
    Scene();
    Scene( Camera camera, int reflectionMaxLevel, Color ambient );
    ~Scene();

    Scene & operator<<( Shape *shape );
    Scene & operator<<( Light *light );

    bool isShadowed( float t, const Ray &ray );
    Color shade( const Vector &v, Shape *shape, const Vector &point );

    Shape *intersect( float *t, const Ray &ray );
    Color trace( const Ray &ray );

    Color getPoint( int x, int y );

    int width();
    int height();
};

#endif//__SCENE_H__
