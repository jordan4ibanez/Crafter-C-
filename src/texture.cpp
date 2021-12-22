#define GLFW_INCLUDE_NONE
#include "texture.h"
#include <iostream>
#include <vector>
#include <GLFW/glfw3.h>
#include "../glad/gl.h"

int Texture::createTexture(std::vector<char> buf){
    //Create a new OpenGL texture
    GLuint textureId;
    glGenTextures(1, &textureId);

    //Bind the texture
    glBindTexture(GL_TEXTURE_2D, textureId);

    //Tell OpenGL how to unpack the RGBA bytes. Each component is 1 byte size
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

    //Turn off texture filtering
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

    //Upload the texture data to the GPU
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, this->width, this->height,
    0, GL_RGBA, GL_UNSIGNED_BYTE, &buf);

    //Generate mipmapping
    //glGenerateMipmap(GL_TEXTURE_2D);

    return(textureId);
}
