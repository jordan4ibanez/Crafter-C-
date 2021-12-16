#include <iostream>
#include <random>
#include "mesh.h"


//this doesn't do anything important at all, it was just to learn C++ with header files and cmake BOI
_Float32 MyDebugTest( _Float32 color){

    float r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);

    color = r;

    return (color);
}