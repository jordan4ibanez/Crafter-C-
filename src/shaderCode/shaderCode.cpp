#define GLFW_INCLUDE_NONE
#include <iostream>
#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include <string>
#include "shaderCode.h"
#include "../debug/log.h"
#include "../explicitIO/explicitIO.h"

GLuint vertex_buffer, vertex_shader, fragment_shader, program;

//yeah this is just copied from the glfw tutorial


/*
const char* vertex_shader_text =
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
*/

static const char* vertex_shader_text = importShader("src/shaderCode/vertex.vs");
 
static const char* fragment_shader_text = importShader("src/shaderCode/fragment.fs");


static const char* getVertexShader(){
    return(vertex_shader_text);
}

static const char* getFragmentShader(){
    return(fragment_shader_text);
}

//this turns that raw text string into actual code :)
void compileShaders(){ 

    /*
    //this is debug on importing shaders from .vs and .fs files
    int size = 0;

    for (char c = *vertex_shader_text; c; c=*++vertex_shader_text) {
        std::cout << c;
        size++;
    }

    vertex_shader_text -= size;
    */

    //first we make the vertex shader come alive
    vertex_shader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex_shader, 1, &vertex_shader_text, NULL);
    glCompileShader(vertex_shader);    
 
    //next we do that frag shader
    fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment_shader, 1, &fragment_shader_text, NULL);
    glCompileShader(fragment_shader);


    //WARNING: this should probably be in it's own file or something :T

    //create the OpenGL shader program
    program = glCreateProgram();
    glAttachShader(program, vertex_shader);
    glAttachShader(program, fragment_shader);
    glLinkProgram(program);

    log("make sure you move the vertex buffer in shaderCode.cpp!!!!");
}

//this is a generic way to get the program ID
//this should probably not be executed like this
//still learning and figuring it out though
GLuint getShaderProgram(){
    return(program);
}

//generic way to get vertex buffer 
/*

MAKE SURE THIS IS MOVED SOMEWHERE THAT MAKE SENSE!

*/

GLuint getVertexBuffer(){
    return(vertex_buffer);
}

GLuint* getVertexBufferPointer(){
    return(&vertex_buffer);
}
