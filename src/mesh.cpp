#define GLFW_INCLUDE_NONE
#include <iostream>
#include <random>
#include <glfw-3.3.6/include/GLFW/glfw3.h>
#include <glad/gl.h>
#include "debug/log.h"
#include <glm/vec3.hpp>
#include <tuple>
#include "mesh.h"


//constructor
Mesh::Mesh(){

}

//destructor - free memory
Mesh::~Mesh(){
    
}

void Mesh::printHi(){
    std::cout << "hi" << std::endl;
}