#include <iostream>
#include <fstream>

#include "ray_tracing.h"

#include "sphere.h"
#include "plane.h"

#include "pointlight.h"

#include "rtimage.h"

using namespace std;

Scene scene;

void constructScene()
{
    Camera camera(Vector(0,2,8), Vector(0,0.5,0), Vector(0,1,0),
                  1366, 768, 0.683, 0.384, 2);
    scene = Scene(camera, 5, Color::white());

    // Create shapes
    Shape *pl = new Plane(Vector(0,0,0), Vector(0,1,0), setMaterial(MAT_SILVER_POLISHED));

    Shape *sph1 = new Sphere(Vector(0,.5,0), .5, setMaterial(MAT_PLASTIC_BLACK));
    sph1->material().reflection() = Color(.8);

    // Add shapes
    scene << pl << sph1; // << new Sphere(Vector(1,0.2,1), 0.2, setMaterial(MAT_GOLD));

    // Add lights
    scene << new PointLight(Vector(8,3,8), Color(1,0,0));
    scene << new PointLight(Vector(-8,3,8), Color(0,1,0));
    scene << new PointLight(Vector(0,4,5), Color(0,0,1));
}

int main( int argc, char *argv[] )
{
    constructScene();
    rtImage image(scene.width(), scene.height());
    image << scene;

    if(argc < 2)
        image.saveImage("result/rt.png");
    else
        image.saveImage(argv[1]);

    return 0;
}
