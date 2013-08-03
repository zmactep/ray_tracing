#include "rtimage.h"

#include <omp.h>
#include <iostream>

rtImage::rtImage( int width, int height )
{
    m_width = width;
    m_height = height;

    m_pData = new unsigned char[m_width * m_height * 3];
}

rtImage::~rtImage()
{
    if( m_pData != NULL )
        delete m_pData;

    m_pData = NULL;
}

//

bool rtImage::setPixel( int x, int y, const Color &color )
{
    int k = (x + y*m_width) * 3;
    int s = m_width * m_height * 3;

    if((k + 2 > s) || (k < 0))
        return false;

    m_pData[k]   = (unsigned char)color.r_c();
    m_pData[k+1] = (unsigned char)color.g_c();
    m_pData[k+2] = (unsigned char)color.b_c();

    return true;
}

bool rtImage::saveImage( const std::string &filename )
{
    int id;

    ilInit();
    iluInit();

    id = ilGenImage();
    ilBindImage(id);

    ilTexImage(m_width, m_height, 1, 3, IL_RGB, IL_UNSIGNED_BYTE, m_pData);
    iluRotate(180);

    return ilSaveImage(filename.c_str());
}


void rtImage::operator<<( Scene &scene )
{
    #pragma omp parallel for
    for( int y = 0; y < m_height; y++ )
        for( int x = 0; x < m_width; x++ )
            setPixel(x, y, scene.getPoint(x, y));
}
