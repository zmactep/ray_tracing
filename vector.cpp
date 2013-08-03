#include "vector.h"

#include <math.h>

//

Vector::Vector()
{
    m_x = m_y = m_z = 0;
}

Vector::Vector( float a )
{
    m_x = m_y = m_z = a;
}

Vector::Vector( float x, float y, float z )
{
    m_x = x;
    m_y = y;
    m_z = z;
}

Vector::Vector( const Vector &v )
{
    m_x = v.m_x;
    m_y = v.m_y;
    m_z = v.m_z;
}

//

float & Vector::x()
{
    return m_x;
}

float & Vector::y()
{
    return m_y;
}

float & Vector::z()
{
    return m_z;
}

float Vector::x_c() const
{
    return m_x;
}

float Vector::y_c() const
{
    return m_y;
}

float Vector::z_c() const
{
    return m_z;
}

//

Vector & Vector::operator=( const Vector &v )
{
    m_x = v.m_x;
    m_y = v.m_y;
    m_z = v.m_z;

    return *this;
}

//

Vector Vector::operator-() const
{
    Vector result;

    result.m_x = -m_x;
    result.m_y = -m_y;
    result.m_z = -m_z;

    return result;
}

//

Vector Vector::operator+( const Vector &v ) const
{
    Vector result;

    result.m_x = m_x + v.m_x;
    result.m_y = m_y + v.m_y;
    result.m_z = m_z + v.m_z;

    return result;
}

Vector Vector::operator-( const Vector &v ) const
{
    Vector result;

    result.m_x = m_x - v.m_x;
    result.m_y = m_y - v.m_y;
    result.m_z = m_z - v.m_z;

    return result;
}

Vector Vector::operator*( const Vector &v ) const
{
    Vector result;

    result.m_x = m_x * v.m_x;
    result.m_y = m_y * v.m_y;
    result.m_z = m_z * v.m_z;

    return result;
}

Vector Vector::operator/( const Vector &v ) const
{
    Vector result;

    result.m_x = m_x / v.m_x;
    result.m_y = m_y / v.m_y;
    result.m_z = m_z / v.m_z;

    return result;
}

//

Vector Vector::operator*( float a ) const
{
    Vector result;

    result.m_x = m_x * a;
    result.m_y = m_y * a;
    result.m_z = m_z * a;

    return result;
}

Vector Vector::operator/( float a ) const
{
    Vector result;

    result.m_x = m_x / a;
    result.m_y = m_y / a;
    result.m_z = m_z / a;

    return result; 
}

//

float Vector::operator%( const Vector &v ) const
{
    return (m_x*v.m_x + m_y*v.m_y + m_z*v.m_z);
}

Vector Vector::operator&( const Vector &v ) const
{
    Vector result;

    result.m_x = m_y*v.m_z - m_z*v.m_y;
    result.m_y = m_z*v.m_x - m_x*v.m_z;
    result.m_z = m_x*v.m_y - m_y*v.m_x;

    return result;
}

//

Vector & Vector::operator+=( const Vector &v )
{
    m_x += v.m_x;
    m_y += v.m_y;
    m_z += v.m_z;

    return *this;
}

Vector & Vector::operator-=( const Vector &v )
{
    m_x -= v.m_x;
    m_y -= v.m_y;
    m_z -= v.m_z;

    return *this;
}

Vector & Vector::operator*=( const Vector &v )
{
    m_x *= v.m_x;
    m_y *= v.m_y;
    m_z *= v.m_z;

    return *this;
}

Vector & Vector::operator/=( const Vector &v )
{
    m_x /= v.m_x;
    m_y /= v.m_y;
    m_z /= v.m_z;

    return *this;
}

Vector & Vector::operator*=( float a )
{
    m_x *= a;
    m_y *= a;
    m_z *= a;

    return *this;
}

Vector & Vector::operator/=( float a )
{
    m_x /= a;
    m_y /= a;
    m_z /= a;

    return *this;
}


float Vector::operator!() const
{
    return sqrt(m_x*m_x + m_y*m_y + m_z*m_z);
}

Vector Vector::normale() const
{
    Vector result;
    float len = !(*this);

    result.m_x = m_x / len;
    result.m_y = m_y / len;
    result.m_z = m_z / len;

    return result;
}

Vector & Vector::normalize()
{
    float len = !(*this);

    m_x /= len;
    m_y /= len;
    m_z /= len;

    return *this;
}


bool Vector::operator==( const Vector &v ) const
{
    return ( fabs(m_x - v.m_x) < EPS &&
             fabs(m_y - v.m_y) < EPS &&
             fabs(m_z - v.m_z) < EPS );
}

bool Vector::operator!=( const Vector &v ) const
{
    return ( fabs(m_x - v.m_x) > EPS ||
             fabs(m_y - v.m_y) > EPS ||
             fabs(m_z - v.m_z) > EPS );
}

