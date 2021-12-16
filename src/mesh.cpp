#include <iostream>
#include <random>
#include "debug/log.h"
#include "mesh.h"
#include <glm/vec3.hpp>
#include <tuple>

//a magical immortal variable
_Float32 color(0.3);

//this doesn't do anything important at all, it was just to learn C++ with header files and cmake BOI
//do not enable this if you are epileptic also I don't know how to spell thank you
 glm::vec3 myDebugTest(){

    glm::vec3 test(1,2,3);

    test.x = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    test.y = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    test.z = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);


    //color = r;

    log(std::to_string(test.x) + " " + std::to_string(test.y) + " " + std::to_string(test.z));

    //apparently vec3 is automatically deleted?

    return(test);
}

_Float32 getColor(){
    return(color);
}
