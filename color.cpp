#include "color.h"
#include <math.h>

#define normComp(x) if (x < 0) x = 0; \
                    else if (x > 1) x = 1;

Color::Color()
{
    m_red = m_green = m_blue = 0;
}

Color::Color( float a )
{
    m_red = m_green = m_blue = a;
}

Color::Color( float red, float green, float blue )
{
    m_red = red;
    m_green = green;
    m_blue = blue;
}

Color::Color( const Color &color )
{
    m_red = color.m_red;
    m_green = color.m_green;
    m_blue = color.m_blue;
}

//

float & Color::r()
{
    return m_red;
}

float & Color::g()
{
    return m_green;
}

float & Color::b()
{
    return m_blue;
}

float Color::r_c() const
{
    return m_red;
}

float Color::g_c() const
{
    return m_green;
}

float Color::b_c() const
{
    return m_blue;
}

//

Color Color::black()
{
    return Color(0);
}

Color Color::white()
{
    return Color(1);
}

//

Color & Color::operator=( const Color &color )
{
    m_red = color.m_red;
    m_green = color.m_green;
    m_blue = color.m_blue;

    return *this;
}

//

Color Color::operator+( const Color &color ) const
{
    Color result;

    result.m_red = m_red + color.m_red;
    result.m_green = m_green + color.m_green;
    result.m_blue = m_blue + color.m_blue;

    return result;
}

Color Color::operator-( const Color &color ) const
{
    Color result;

    result.m_red = m_red - color.m_red;
    result.m_green = m_green - color.m_green;
    result.m_blue = m_blue - color.m_blue;

    return result;
}

Color Color::operator*( const Color &color ) const
{
    Color result;

    result.m_red = m_red * color.m_red;
    result.m_green = m_green * color.m_green;
    result.m_blue = m_blue * color.m_blue;

    return result;
}

Color Color::operator/( const Color &color ) const
{
    Color result;

    result.m_red = m_red / color.m_red;
    result.m_green = m_green / color.m_green;
    result.m_blue = m_blue / color.m_blue;

    return result;
}

//

Color Color::operator+( float a ) const
{
    Color result;

    result.m_red = m_red + a;
    result.m_green = m_green + a;
    result.m_blue = m_blue + a;

    return result;
}

Color Color::operator-( float a ) const
{
    Color result;

    result.m_red = m_red - a;
    result.m_green = m_green - a;
    result.m_blue = m_blue - a;

    return result;
}

Color Color::operator*( float a ) const
{
    Color result;

    result.m_red = m_red * a;
    result.m_green = m_green * a;
    result.m_blue = m_blue * a;

    return result;
}

Color Color::operator/( float a ) const
{
    Color result;

    result.m_red = m_red / a;
    result.m_green = m_green / a;
    result.m_blue = m_blue / a;

    return result;
}

//

Color & Color::operator+=( const Color &color )
{
    m_red += color.m_red;
    m_green += color.m_green;
    m_blue += color.m_blue;

    return *this;
}

Color & Color::operator-=( const Color &color )
{
    m_red -= color.m_red;
    m_green -= color.m_green;
    m_blue -= color.m_blue;

    return *this;
}

Color & Color::operator*=( const Color &color )
{
    m_red *= color.m_red;
    m_green *= color.m_green;
    m_blue *= color.m_blue;

    return *this;
}

Color & Color::operator/=( const Color &color )
{
    m_red /= color.m_red;
    m_green /= color.m_green;
    m_blue /= color.m_blue;

    return *this;
}

//

Color & Color::operator+=( float a )
{
    m_red += a;
    m_green += a;
    m_blue += a;

    return *this;
}

Color & Color::operator-=( float a )
{
    m_red -= a;
    m_green -= a;
    m_blue -= a;

    return *this;
}

Color & Color::operator*=( float a )
{
    m_red *= a;
    m_green *= a;
    m_blue *= a;

    return *this;
}

Color & Color::operator/=( float a )
{
    m_red /= a;
    m_green /= a;
    m_blue /= a;

    return *this;
}

//

bool Color::operator==( const Color &color )
{
    return ( fabs(m_red - color.m_red) < COLOR_EPS &&
             fabs(m_green - color.m_green) < COLOR_EPS &&
             fabs(m_blue - color.m_blue) < COLOR_EPS );
}

bool Color::operator!=( const Color &color )
{
    return ( fabs(m_red - color.m_red) > COLOR_EPS ||
             fabs(m_green - color.m_green) > COLOR_EPS ||
             fabs(m_blue - color.m_blue) > COLOR_EPS );
}

bool Color::operator>( const Color &color )
{
    return ( m_red > color.m_red && 
             m_green > color.m_green &&
             m_blue > color.m_blue);
}
bool Color::operator<( const Color &color )
{
    return ( m_red < color.m_red && 
             m_green < color.m_green &&
             m_blue < color.m_blue);
}

//

Color & Color::normalize()
{
    normComp(m_red);
    normComp(m_green);
    normComp(m_blue);

    return *this;
}

Color Color::trunk() const
{
    Color result;

    result.m_red = (int)(255 * m_red);
    result.m_green = (int)(255 * m_green);
    result.m_blue = (int)(255 * m_blue);

    return result;
}

#undef normComp
