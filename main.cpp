#include <iostream>
#include <GLFW/glfw3.h>

int main() {
    if(!glfwInit()) {
        printf("Can not init GLFW");
    }

    GLFWwindow* window = glfwCreateWindow(640, 480, "My GLFW Title", NULL, NULL);

    while (!glfwWindowShouldClose(window))
    {
        

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}