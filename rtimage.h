#ifndef __RT_IMAGE_H__
#define __RT_IMAGE_H__

#include <string>

#include <IL/il.h>
#include <IL/ilu.h>

#include "color.h"
#include "scene.h"

class rtImage
{
private:
    int m_width, m_height;
    unsigned char *m_pData;

public:
    rtImage( int width = 640, int height = 480 );
    ~rtImage();

    bool setPixel( int x, int y, const Color &color );
    bool saveImage( const std::string &filename );

    void operator<<( Scene &scene );
};

#endif//__RT_IMAGE_H__
