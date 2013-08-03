#ifndef __VECTOR_H__
#define __VECTOR_H__

#define EPS 0.0005

class Vector
{
private:
    float m_x, m_y, m_z;

public:
    Vector();
    Vector( float a );
    Vector( float x, float y, float z );
    Vector( const Vector &v );


    float & x();
    float & y();
    float & z();

    float x_c() const;
    float y_c() const;
    float z_c() const;

    Vector & operator=( const Vector &v );

    Vector operator-() const;

    Vector operator+( const Vector &v ) const;
    Vector operator-( const Vector &v ) const;
    Vector operator*( const Vector &v ) const;
    Vector operator/( const Vector &v ) const;

    Vector operator*( float a ) const;
    Vector operator/( float a ) const;


    float operator%( const Vector &v ) const;
    Vector operator&( const Vector &v ) const;


    Vector & operator+=( const Vector &v );
    Vector & operator-=( const Vector &v );
    Vector & operator*=( const Vector &v );
    Vector & operator/=( const Vector &v );

    Vector & operator*=( float a );
    Vector & operator/=( float a );


    float operator!() const;
    Vector normale() const;
    Vector & normalize();


    bool operator==( const Vector &v ) const;
    bool operator!=( const Vector &v ) const;
};


#endif
