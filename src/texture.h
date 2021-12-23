#pragma once
#include <iostream>
#include <vector>
#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_STATIC
#include <stb/stb_image.h>

//java Crafter's texture class translated to C++
//OOP as can be
class Texture{
    private:

    //GL data variables
    int id;
    int width;
    int height;

    //literal OpenGL data creation in memory - return ID
    int createTexture(const void* buf);

    public:

    //constructor - intakes filename
    Texture(const char * fileName);
    //constructor - intakes data from other texture
    Texture(const stbi_uc * imageBuffer);


    //destructor - needs to clean up memory
    ~Texture();
};