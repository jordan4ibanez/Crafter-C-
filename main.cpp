#include <iostream>
#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include "src/mesh.h"
#include "src/debug/log.h"
#include <glm/vec3.hpp>
#include "src/chunk.h"


int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit()){
        log("GLFW COULD NOT INITIALIZE!");
        return -1;
    }    

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Crafter?", NULL, NULL);

    //This is debug, basically sending the window pointer to null and crashing glfw.
    //This is implemented to test the crashing on non-supported (outdated)
    //graphics hardware on individual operating systems.
    //window = NULL;

    if (!window) {
        glfwTerminate();
        logHeader("GLFW ERROR");
        log("GL WINDOW WAS NOT ABLE TO BE CREATED!");
        log("EXIT REASON:" + std::to_string(EXIT_FAILURE));
        logFooter();
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

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window)) {

        glClearColor(0.3,0.3,0.3,1);


        log(std::to_string(glfwGetTime()));
        glfwSetTime(0);
        //testMyChunk();
        //do not enable this if you are epileptic
        //glm::vec3 color = myDebugTest();
        //glClearColor(color.x,color.y,color.z,1);

        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}