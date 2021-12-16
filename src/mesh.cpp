#include <iostream>
#include <random>
#include "mesh.h"

//a magical immortal variable
_Float32 color(0.3);

//this doesn't do anything important at all, it was just to learn C++ with header files and cmake BOI
_Float32 myDebugTest( _Float32 color){

    float r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);

    color = r;

    return (color);
}

_Float32 getColor(){
    return(color);
}