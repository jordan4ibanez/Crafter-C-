#pragma once
#include <iostream>
#include <tuple>
#include <glm/vec3.hpp>
#include "texture.h"

class Mesh{
    private:

    int posVboId;
    int colorVboId;
    int textureVboId;
    int idxVboId;
    int vertexCount;

    Texture texture;

    public:

    //constructor
    Mesh();

    //destructor - free memory
    ~Mesh();
};