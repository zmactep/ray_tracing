#include "camera.h"

Camera::Camera()
{
}

Camera::Camera( Vector location, Vector lookAt, Vector up,
                int mx, int my, float wp, float hp, float distance)
{
    m_location = location;
    m_direction = (lookAt - m_location).normale();
    m_right = (m_direction & up).normale();
    m_up = (m_right & m_direction).normale();

    m_mx = mx;
    m_my = my;

    m_wp = wp;
    m_hp = hp;
    m_distance = distance;
}

//

void Camera::move( Vector location, Vector lookAt, Vector up )
{
    m_location = location;
    m_direction = (lookAt - m_location).normale();
    m_right = (m_direction & up).normale();
    m_up = (m_right & m_direction).normale();   
}

void Camera::apply( Ray &ray, int x, int y )
{
    Vector toScreen;

    toScreen = m_direction * m_distance +
               m_right * (x - m_mx/2) * (m_wp/m_mx) +
               m_up * (m_my/2 - y) * (m_hp/m_my);

    ray = Ray(m_location + toScreen, toScreen.normale());
}

int Camera::width()
{
    return m_mx;
}

int Camera::height()
{
    return m_my;
}
