#include <iostream>
#include <GLFW/glfw3.h>
//#include "debug/log.h"

/*
Keep in mind, this is all working with REAL TIME, in a 64 bit float.
This will give you REAL TIME second accuracy.
1.0 = 1.0 seconds
*/


//immortal delta/uptime variables
_Float64 deltaTime(0.0);
//_Float128 will probably cause performance problems, probably don't need that much uptime precision in a game
_Float64 upTime(0.0);

void tickDelta(){
    //this is to be used as program delta time in the future
    //it is a float -> assumed to be 64 bit but platform dependant, see https://www.glfw.org/docs/3.0/group__time.html
    deltaTime = glfwGetTime();
    //debug terminal logging - make sure you uncomment the debug/log.h inclusion
    //log(std::to_string(deltaTime));
    //tick up the uptime, in case this is needed for some reason
    upTime += deltaTime;
    //this resets the timer to maintain float accuracy
    glfwSetTime(0);
}

//easy way to get the delta time
_Float64 getDelta(){
    return(deltaTime);
}

//easy way to get the uptime (in seconds)
_Float64 getUptime(){
    return(upTime);
}