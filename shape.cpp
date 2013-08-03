#include "shape.h"

Material & Shape::material()
{
    return m_material;
}


Material Shape::material_c() const
{
    return m_material;
}
