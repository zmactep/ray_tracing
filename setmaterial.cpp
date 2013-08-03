#include "setmaterial.h"

Material setMaterial( int materialID )
{
    Material material;

    switch(materialID) 
    {
    case 0:
        material.ambient() = Color(0.24725, 0.1995, 0.0745);
        material.diffuse() = Color(0.75164, 0.60648, 0.22648);
        material.specular() = Color(0.628281, 0.555802, 0.366065);
        material.phong() = 51.2;
        break;
    case 1:
        material.ambient() = Color(0.19225);
        material.diffuse() = Color(0.50754);
        material.specular() = Color(0.508273);
        material.phong() = 51.2;
        break;
    case 2:
        material.ambient() = Color(0.23125);
        material.diffuse() = Color(0.2775);
        material.specular() = Color(0.773911);
        material.phong() = 89.6;
        break;
    case 3:
        material.ambient() = Color(0.2125, 0.1275, 0.054);
        material.diffuse() = Color(0.714, 0.4284, 0.18144);
        material.specular() = Color(0.393548, 0.271906, 0.166721);
        material.phong() = 25.6;
        break;
    case 4:
        material.ambient() = Color(0.25);
        material.diffuse() = Color(0.4);
        material.specular() = Color(0.774597);
        material.phong() = 76.8;
        break;
    case 5:
        material.ambient() = Color(0.329412, 0.223529, 0.027451);
        material.diffuse() = Color(0.780392, 0.568627, 0.113725);
        material.specular() = Color(0.992157, 0.941176, 0.807843);
        material.phong() = 27.8974;
        break;
    case 6:
        material.ambient() = Color(0.10588, 0.058824, 0.113724);
        material.diffuse() = Color(0.427451, 0.470588, 0.541176);
        material.specular() = Color(0.3333, 0.3333, 0.521569);
        material.phong() = 9.84615;
        break;
    case 7:
        material.ambient() = Color(0.19125, 0.0735, 0.0225);
        material.diffuse() = Color(0.7038, 0.27048, 0.0828);
        material.specular() = Color(0.256777, 0.137622, 0.086014);
        material.phong() = 12.8;
        break;
    case 8:
        material.ambient() = Color(0);
        material.diffuse() = Color(0.1);
        material.specular() = Color(0.5);
        material.phong() = 32;
        break;
    case 9: 
        material.color() = Color(1, 0, 0);
        break;
    case 10: 
        material.color() = Color(0, 1, 0);
        break;
    case 11: 
        material.color() = Color(0, 0, 1);
        break;
    case 12: 
        material.color() = Color(1, 1, 1);
        break;
    case 13: 
        material.color() = Color(0, 0, 0);
        break;
    }

    return material;
}
