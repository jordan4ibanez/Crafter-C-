#include <iostream>
#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include <string>
#include <fstream>
#include "shaderCode.h"
#include "../debug/log.h"

/*
TODO:

Make this load from a .txt or .v or .c literally anything but hardcoded strings

*/

GLuint vertex_buffer, vertex_shader, fragment_shader, program;


//yeah this is just copied from the glfw tutorial
static const char* vertex_shader_text =
"#version 110\n"
"uniform mat4 MVP;\n"
"attribute vec3 vCol;\n"
"attribute vec2 vPos;\n"
"varying vec3 color;\n"
"void main()\n"
"{\n"
"    gl_Position = MVP * vec4(vPos, 0.0, 1.0);\n"
"    color = vCol;\n"
"}\n";
 
static const char* fragment_shader_text =
"#version 110\n"
"varying vec3 color;\n"
"void main()\n"
"{\n"
"    gl_FragColor = vec4(color, 1.0);\n"
"}\n";


static const char* getVertexShader(){
    return(vertex_shader_text);
}

static const char* getFragmentShader(){
    return(fragment_shader_text);
}

//this turns that raw text string into actual code :)
void compileShaders(){

    std::fstream newfile;
    newfile.open("src/shaderCode/vertex.vs",std::ios::in);

    std::string realOutput;
    std::string readOutput;

    if (newfile.is_open()){
        while(std::getline(newfile, readOutput)){ //read data from file object and put it into string.
            //std::cout << test << "\n"; //print the data of the string
            realOutput += readOutput + "\n";
        }
        newfile.close();
    }

    //log("hi there");

    std::cout << realOutput << std::endl;

    logFooter();

    //first we make the vertex shader come alive
    vertex_shader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex_shader, 1, &vertex_shader_text, NULL);
    glCompileShader(vertex_shader);
 
    //next we do that frag shader
    fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment_shader, 1, &fragment_shader_text, NULL);
    glCompileShader(fragment_shader);
}