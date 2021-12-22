#pragma once
#include <iostream>
#include <vector>

//java Crafter's texture class translated to C++
//OOP as can be
class Texture{
    private:

    //GL data variables
    const int id;
    const int width;
    const int height;

    int createTexture(std::vector<char> buf);

    public:

    //constructor
    Texture(std::string fileName);


    //destructor - needs to clean up memory
    ~Texture();


};