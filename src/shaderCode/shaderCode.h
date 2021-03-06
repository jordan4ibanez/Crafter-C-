#pragma once

static const char* getVertexShader();

static const char* getFragmentShader();

void compileShaders();

GLuint getShaderProgram();

GLuint getVertexBuffer();

GLuint* getVertexBufferPointer();