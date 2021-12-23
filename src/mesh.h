#pragma once
#include <iostream>
#include <tuple>
#include <glm/vec3.hpp>
#include "texture.h"
#include <vector>

class Mesh{
    private:

    GLuint * vaoId;



    GLuint * posVboId;
    GLuint * colorVboId;
    GLuint * textureVboId;
    GLuint * idxVboId;

    int vertexCount;

    Texture texture;

    public:

    //constructor
    Mesh(std::vector<float> positions, std::vector<float> colors, std::vector<int> indices, std::vector<float> textCoords, Texture texture);

    void render();

    //destructor - free memory
    ~Mesh();
};