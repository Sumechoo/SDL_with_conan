#include <iostream>
#include <GLFW/glfw3.h>

#include "./lib/controller.cpp"
#include "./lib/renderer.cpp"

int main() {
    if(!glfwInit()) {
        printf("Can not init GLFW");
    }

    GLFWwindow* window = glfwCreateWindow(640, 480, "My GLFW Title", NULL, NULL);

    new Controller(window);

    glfwMakeContextCurrent(window);

    while (!glfwWindowShouldClose(window))
    {
        glClearColor(255, 0, 0, 1);
        glClear(GL_COLOR_BUFFER_BIT);

        GLint windowWidth, windowHeight;
        glfwGetWindowSize(window, &windowWidth, &windowHeight);
        glViewport(0, 0, windowWidth, windowHeight);

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glMatrixMode(GL_PROJECTION_MATRIX);
        glLoadIdentity();

        drawCube();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}