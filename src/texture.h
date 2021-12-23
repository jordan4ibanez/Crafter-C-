#pragma once
#define GLFW_INCLUDE_NONE
#include <iostream>
#include <vector>
#include "../glad/gl.h"
#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_STATIC
#include <stb/stb_image.h>

//java Crafter's texture class translated to C++
//OOP as can be
class Texture{
    private:

    //GL data variables
    const GLuint * id;
    int width;
    int height;

    //literal OpenGL data creation in memory - return ID
    const GLuint * createTexture(const void* buf);

    public:

    //constructor - blank
    Texture();
    //constructor - intakes filename
    Texture(const char * fileName);
    //constructor - intakes data from other texture
    Texture(const stbi_uc * imageBuffer);

    int getWidth();

    int getHeight();

    const GLuint * getId();


    //destructor - needs to clean up memory
    ~Texture();

    //clean up GL data
    void cleanUp();
};