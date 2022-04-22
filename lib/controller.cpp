#include <iostream>

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (action == GLFW_PRESS) {
        switch (key) {
            case GLFW_KEY_ESCAPE:
                glfwSetWindowShouldClose(window, GLFW_TRUE);
                break;
        }
    }
}

class Controller {
    public:
        Controller(GLFWwindow* window) {
            printf("Controller created");

            glfwSetKeyCallback(window, key_callback);
        }
};
