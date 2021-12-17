#include <iostream>
#include <GLFW/glfw3.h>
//#include "debug/log.h"

//immortal delta/uptime variables
_Float64 deltaTime(0.0);
//_Float128 will probably cause performance problems, probably don't need that much uptime precision in a game
_Float64 upTime(0.0);

void tickDelta(){
    //this is to be used as program delta time in the future
    //it is a float -> assumed to be 64 bit but platform dependant, see https://www.glfw.org/docs/3.0/group__time.html
    deltaTime = glfwGetTime();
    //debug terminal logging
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