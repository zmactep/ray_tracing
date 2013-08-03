#include "scene.h"

#include <math.h>

Scene::Scene()
{
//    Camera( Vector location, Vector lookAt, Vector up,
//            int mx, int my, float wp, float hp, float distance);

    m_camera = Camera(Vector(0,5,10), Vector(0,0,0), Vector(0,1,0),
                    640, 480, 0.4, 0.3, 1);
    m_reflectionMaxLevel = 5;
    m_reflectionLevel = 0;
    m_ambient = Color::white();
}

Scene::Scene( Camera camera, int reflectionMaxLevel, Color ambient )
{
    m_camera = camera;
    m_reflectionMaxLevel = reflectionMaxLevel;
    m_reflectionLevel = 0;
    m_ambient = ambient;
}

Scene::~Scene()
{
    for( int i = m_shapes.size() - 1; i >= 0; i-- )
    {
        delete m_shapes[i];
        m_shapes[i] = NULL;
    }

    for( int i = m_lights.size() - 1; i >= 0; i-- )
    {
        delete m_lights[i];
        m_lights[i] = NULL;
    }
}

//

Scene & Scene::operator<<( Shape *shape )
{
    m_shapes.push_back(shape);

    return *this;
}

Scene & Scene::operator<<( Light *light )
{
    m_lights.push_back(light);

    return *this;
}

//

bool Scene::isShadowed( float t, const Ray &ray )
{
    float k;

    for( int i = 0; i < m_shapes.size(); i++ )
        if( (k = m_shapes[i]->intersect(ray)) != -1 )
            if( k < t )
                return false;

    return true;
}

Color Scene::shade( const Vector &v, Shape *shape, const Vector &point )
{
    Color color(0);

    Vector normale = shape->getNormal(point);

    if( normale % v > 0 )
        normale = -normale;

    // Ambient
    color += m_ambient * shape->material().color()
                       * shape->material().ambient();

    float li;
    float rdir;

    Vector lp;
    Ray ray;

    Color reflectionPower = Color::white();
    Vector reflection;
    for( int i = 0; i < m_lights.size(); i++ )
    {
        li = m_lights[i]->shade(lp, point, normale);

        ray = Ray(point, lp.normale());
        ray.location() += ray.direction() * EPS;

        if( isShadowed(!lp - EPS, ray) )
        {
            // Diffuse
            color += m_lights[i]->color() * li *
                     shape->material().color() *
                     shape->material().diffuse();

            // Specular && Phong
            rdir = (lp.normale() - v).normale() % normale;
            if( rdir > 0 )
                color += m_lights[i]->color() *
                         shape->material().specular() *
                         pow(rdir, shape->material().phong());

        }

        // Reflection
        reflection = (v - normale * 2 * (v % normale)).normale();

        if( shape->material().reflection() != 0 && 
            m_reflectionLevel < m_reflectionMaxLevel )
        {
            m_reflectionLevel++;
            reflectionPower *= shape->material().reflection();
            if( reflectionPower > Color(REFLECTION_EPS) )
            {
                ray.location() = point + reflection * EPS;
                ray.direction() = reflection;

                color += trace(ray) * shape->material().reflection() *
                         reflectionPower;
            }

            m_reflectionLevel--;
        }
        reflectionPower = Color::white();
    }

    return color;
}

//

Shape *Scene::intersect( float *t, const Ray &ray )
{
    float minT, tmpT;
    Shape *minShape;

    minT = -255;
    minShape = NULL;

    for( int i = 0; i < m_shapes.size(); i++ )
        if( (tmpT = m_shapes[i]->intersect(ray)) != -1 )
            if( minT == -255 || tmpT < minT )
            {
                minT = tmpT;
                minShape = m_shapes[i];
            }

    if( minShape != NULL )
        *t = minT;

    return minShape;
}

Color Scene::trace( const Ray &ray )
{
    Shape *shape;
    float t;

    shape = intersect(&t, ray);

    if( shape == NULL )
        return Color::black();

    return shade(ray.direction_c(), shape, ray.apply(t));
}


Color Scene::getPoint( int x, int y )
{
    Ray ray;
    Color color;

    m_camera.apply(ray, x, y);
    color = trace(ray);
    color.normalize();

    return color.trunk();
}

int Scene::width()
{
    return m_camera.width();
}

int Scene::height()
{
    return m_camera.height();
}
