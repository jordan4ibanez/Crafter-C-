#include <iostream>
#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include "src/mesh.h"
#include "src/debug/log.h"
#include <glm/vec3.hpp>
#include "src/chunk.h"
#include "src/deltaTime.h"
#include "src/shaderCode/shaderCode.h"

int main(void)
{
    //window pointer
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit()){
        logAuto("GLFW ERROR","GLFW COULD NOT INITIALIZE!");
        return -1;
    }

    //using opengl 4.4
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);

    //Create a windowed mode window and its OpenGL context
    //automatically redirecting window pointer to new memory location
    window = glfwCreateWindow(640, 480, "Crafter C++ - Prototyping Engine Build", NULL, NULL);

    //This is debug, basically sending the window pointer to null and crashing glfw.
    //This is implemented to test the crashing on non-supported (outdated)
    //graphics hardware on individual operating systems.
    //window = NULL;

    //log crash
    if (!window) {
        glfwTerminate();
        logAuto("GLFW ERROR", "GL WINDOW WAS NOT ABLE TO BE CREATED!");
        glfwTerminate();
        exit(EXIT_FAILURE);
        return(EXIT_FAILURE);
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    //load gl into glad
    gladLoadGL(glfwGetProcAddress);

    //0 MAX SPEED!
    //1 regular vsync
    //2 double buffered
    //3 triple buffered <- great on low end systems maybe?
    glfwSwapInterval(1);

    //build the glsl shaders
    compileShaders();

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window)) {

        tickDelta();

        glClearColor(0.3,0.3,0.3,1);

        //int w = 54555;
        //mutableTest(w);
        //log(std::to_string(w));

        //testMyChunk();
        //do not enable this if you are epileptic
        //glm::vec3 color = myDebugTest();
        //glClearColor(color.x,color.y,color.z,1);

        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);


        glUseProgram(getProgram());

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwDestroyWindow(window);

    glfwTerminate();

    exit(EXIT_SUCCESS);
    
    return 0;
}