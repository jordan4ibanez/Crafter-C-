#include <iostream>
#include <string>
#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include "shaderCode.h"

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

//this turns that raw text into actual code :)
void compileShaders(){
    //first we make the vertex shader come alive
    vertex_shader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex_shader, 1, &vertex_shader_text, NULL);
    glCompileShader(vertex_shader);
 
    //next we do that frag shader
    fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment_shader, 1, &fragment_shader_text, NULL);
    glCompileShader(fragment_shader);
}