#define GLFW_INCLUDE_NONE
#include <iostream>
#include <GLFW/glfw3.h>
#include "keyBoard.h"
#include "../debug/log.h"

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS){
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }


    //log(std::to_string(action));

    if (key == GLFW_KEY_UP){
        log("up!");
    } else if (key == GLFW_KEY_DOWN){
        log("down!");
    }
}