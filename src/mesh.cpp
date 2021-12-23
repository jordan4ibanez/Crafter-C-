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
#include <vector>
#include <array>


//constructor
Mesh::Mesh(std::vector<float> positions, std::vector<float> colors, std::vector<int> indices, std::vector<float> textCoords, Texture texture){
    this->texture = texture;

    this->vertexCount = indices.size();

    //C++ generation is slightly different
    //consumes/mutability vs void & returning in lwjgl
    glGenVertexArrays(1,this->vaoId);
    glBindVertexArray(*this->vaoId);

    //position VBO
    glGenBuffers(1,this->posVboId);
    float posBuffer[positions.size()];

    //posBuffer.put(positions).flip();
    for (int i = 0; i < positions.size(); i++){
        posBuffer[i] = positions[i];
    }

    glBindBuffer(GL_ARRAY_BUFFER, *this->posVboId);
    glBufferData(GL_ARRAY_BUFFER, 1, &posBuffer, 1);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, false, 0, 0);

    //color VBO
    glGenBuffers(1,this->colorVboId);
    float colorBuffer[colors.size()];
    
    //colorBuffer.put(colors).flip();
    for (int i = 0; i < colors.size(); i++){
        colorBuffer[i] = colors[i];
    }

    glBindBuffer(GL_ARRAY_BUFFER, *this->colorVboId);
    glBufferData(GL_ARRAY_BUFFER, 1, &colorBuffer, 1);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, false, 0, 0);

    //texture coordinates vbo
    glGenBuffers(1,this->textureVboId);
    float textCoordsBuffer[textCoords.size()];

    //textCoordsBuffer.put(textCoords).flip();
    for (int i = 0; i < textCoords.size(); i++){
        textCoordsBuffer[i] = textCoords[i];
    }

    glBindBuffer(GL_ARRAY_BUFFER, *this->textureVboId);
    glBufferData(GL_ARRAY_BUFFER, 1, textCoordsBuffer, 1);
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, false, 0, 0);

    //index vbo
    glGenBuffers(1,this->idxVboId);
    int indicesBuffer[indices.size()];
    
    //indicesBuffer.put(indices).flip();
    for (int i = 0; i < indices.size(); i++){
        indicesBuffer[i] = indices[i];
    }

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, *this->idxVboId);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, 1, indicesBuffer, 1);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    free(posBuffer);
    free(colorBuffer);
    free(textCoordsBuffer);
    free(indicesBuffer);

}


void Mesh::render(){
    //activate first texture bank
        glActiveTexture(GL_TEXTURE0);

        //bind the texture
        glBindTexture(GL_TEXTURE_2D, *this->texture.getId());

        //draw the mesh
        glBindVertexArray(*this->vaoId);
        glEnableVertexAttribArray(0);
        glEnableVertexAttribArray(1);

        glDrawElements(GL_TRIANGLES, this->vertexCount, GL_UNSIGNED_INT, 0);

        //restore data
        glDisableVertexAttribArray(0);
        glDisableVertexAttribArray(1);
        glBindVertexArray(0);
}

//destructor - free memory
Mesh::~Mesh(){
    
}