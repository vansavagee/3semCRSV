#include<glad/glad.h>
#include<glfw/glfw3.h>
#include<iostream>
int main() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
   /* glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);*/
    GLFWwindow* window = glfwCreateWindow(800, 800, "blabla", NULL, NULL);
    if (!window) {
        std::cout << "Fail, but dont give up anyway!!!" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    if (!gladLoadGL()) {
        std::cout << "GLAD error!" << std::endl;
        return -1;
    }
    std::cout << "OpenGL" << GLVersion.major << '.' << GLVersion.minor << std::endl;

    glClearColor(0, 1, 0, 1);
    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
    glfwTerminate();
	std::cout << "blsblsbla" << std::endl;
	return 0;
}