#include <iostream>
#include <GLFW/glfw3.h>

_Float64 test = 0.0;

bool up = true;

void testGlClearColor(){

    if (up){
        test += 0.01;
        if (test >= 1){
            up = false;
        }
    } else {
        test -= 0.01;
        if (test <= 0){
            up = true;
        }
    }

    std::cout << test << std::endl;

}

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "An Experiment", NULL, NULL);

    //test that this works on all OSes
    //window = NULL;

    if (!window) {
        glfwTerminate();
        std::cout << "GL WINDOW WAS NOT ABLE TO BE CREATED!" << std::endl;
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window)) {   
        
        testGlClearColor();

        glClearColor(test,test,test,1);

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