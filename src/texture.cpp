#define GLFW_INCLUDE_NONE
#include <iostream>
#include "texture.h"
#include <vector>
#include <GLFW/glfw3.h>
#include "../glad/gl.h"
#include <stb/stb_image.h>
#include "debug/log.h"

//private texture creation in OpenGL - literal data
int Texture::createTexture(const void* buf){
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

    //&BUF MIGHT CAUSE PROBLEMS! NEEDS const void*!!
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, this->width, this->height,
    0, GL_RGBA, GL_UNSIGNED_BYTE, buf);

    //Generate mipmapping
    //glGenerateMipmap(GL_TEXTURE_2D);

    return(textureId);
};

Texture::Texture(const char * fileName){
    const stbi_uc *  buf;

    int * w = (int *) malloc(1);
    int * h = (int *) malloc(1);
    int * channels = (int *) malloc(1);

    buf = stbi_load(fileName, w, h, channels, 4);

    //this probably isn't correct but it's in here
    //throw error if nullptr
    if (buf == nullptr){
        throw new error_t();
    };

    //this can cause errors if nullptr, probably should check
    this->width = *w;
    this->height = *h;

    this->id = createTexture(buf);

    log("remember to check for memory leaks in texture.cpp!");
};