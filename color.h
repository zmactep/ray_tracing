#ifndef __COLOR_H__
#define __COLOR_H__

#define COLOR_EPS 0.0005
#define REFLECTION_EPS 0.01

class Color
{
private:
    float m_red;
    float m_green;
    float m_blue;

public:
    Color();
    Color( float a );
    Color( float red, float green, float blue );
    Color( const Color &color );

    float & r();
    float & g();
    float & b();

    float r_c() const;
    float g_c() const;
    float b_c() const;

    static Color black();
    static Color white();

    Color & operator=( const Color &color );

    Color operator+( const Color &color ) const;
    Color operator-( const Color &color ) const;
    Color operator*( const Color &color ) const;
    Color operator/( const Color &color ) const;

    Color operator+( float a ) const;
    Color operator-( float a ) const;
    Color operator*( float a ) const;
    Color operator/( float a ) const;

    Color & operator+=( const Color &color );
    Color & operator-=( const Color &color );
    Color & operator*=( const Color &color );
    Color & operator/=( const Color &color );

    Color & operator+=( float a );
    Color & operator-=( float a );
    Color & operator*=( float a );
    Color & operator/=( float a );

    bool operator==( const Color &color );
    bool operator!=( const Color &color );
    bool operator>( const Color &color );
    bool operator<( const Color &color );

    Color & normalize();
    Color trunk() const;
};

#endif//__COLOR_H__
