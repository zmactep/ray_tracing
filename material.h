#ifndef __MATERIAL_H__
#define __MATERIAL_H__

#include "color.h"

class Material
{
private:
    Color m_color;
    Color m_ambient;
    Color m_diffuse;
    Color m_specular;
    Color m_transaction;
    Color m_reflection;

    float m_phong;

public:
    Material();
    Material( const Color &color, const Color &ambient, 
              const Color &diffuse, const Color &specular, 
              const Color &transaction, const Color &reflection,
              float phong);

    Color & color();
    Color & ambient();
    Color & diffuse();
    Color & specular();
    Color & transaction();
    Color & reflection();
    float & phong();

    Color color_c() const;
    Color ambient_c() const;
    Color diffuse_c() const;
    Color specular_c() const;
    Color transaction_c() const;
    Color reflection_c() const;
    float phong_c() const;

    Color & setReflection( const Color & reflection );
};

#endif//__MATERIAL_H__
