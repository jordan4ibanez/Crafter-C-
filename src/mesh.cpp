#include <iostream>
#include <random>
#include "mesh.h"

_Float32 MyDebugTest( _Float32 color){

    float r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);

    std::cout << r << std::endl;

    color = r;

    std::cout << "Test was guude! Color: " << color << std::endl;

    return (color);
}