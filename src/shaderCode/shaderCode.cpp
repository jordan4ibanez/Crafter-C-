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

    //importShader("src/shaderCode/vertex.vs");

    //first we make the vertex shader come alive
    vertex_shader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex_shader, 1, &vertex_shader_text, NULL);
    glCompileShader(vertex_shader);
 
    //next we do that frag shader
    fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment_shader, 1, &fragment_shader_text, NULL);
    glCompileShader(fragment_shader);


    //WARNING: this should probably be in it's own file or something :T

    program = glCreateProgram();
    glAttachShader(program, vertex_shader);
    glAttachShader(program, fragment_shader);
    glLinkProgram(program);
}

//this is a generic way to get the program ID
//this should probably not be executed like this
//still learning and figuring it out though
GLuint getShaderProgram(){
    return(program);
}