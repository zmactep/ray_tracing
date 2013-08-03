#include "material.h"

Material::Material()
{
    m_color = 1;
    m_ambient = 0.1;
    m_diffuse = 0.9;
    m_specular = 0;
    m_transaction = 0;
    m_reflection = 0;
    m_phong = 0;
}

Material::Material( const Color &color, const Color &ambient, 
                    const Color &diffuse, const Color &specular, 
                    const Color &transaction, const Color &reflection,
                    float phong)
{
    m_color = color;
    m_ambient = ambient;
    m_diffuse = diffuse;
    m_specular = specular;
    m_transaction = transaction;
    m_reflection = reflection;
    m_phong = phong;
}

//

Color & Material::color()
{
    return m_color;
}

Color & Material::ambient()
{
    return m_ambient;
}

Color & Material::diffuse()
{
    return m_diffuse;
}

Color & Material::specular()
{
    return m_specular;
}

Color & Material::transaction()
{
    return m_transaction;
}

Color & Material::reflection()
{
    return m_reflection;
}

float & Material::phong()
{
    return m_phong;
}

//

Color Material::color_c() const
{
    return m_color;
}

Color Material::ambient_c() const
{
    return m_ambient;
}

Color Material::diffuse_c() const
{
    return m_diffuse;
}

Color Material::specular_c() const
{
    return m_specular;
}

Color Material::transaction_c() const
{
    return m_transaction;
}

Color Material::reflection_c() const
{
    return m_reflection;
}

float Material::phong_c() const
{
    return m_phong;
}

Color & Material::setReflection( const Color & reflection )
{
    m_reflection = reflection;

    return m_reflection;
}
