#define GLFW_INCLUDE_NONE
#include <iostream>
#include <random>
#include <glfw-3.3.6/include/GLFW/glfw3.h>
#include <glad/gl.h>
#include "debug/log.h"
#include <glm/vec3.hpp>
#include <tuple>
#include "mesh.h"
#include "texture.h"


//constructor
Mesh::Mesh(){
    this->posVboId = 5;
    this->posVboId = 10;
    this->colorVboId = 1;
    this->textureVboId = 5;
    this->idxVboId = 5;
    this->texture.cleanUp();
    this->texture = ("hi");
}

//destructor - free memory
Mesh::~Mesh(){
    
}