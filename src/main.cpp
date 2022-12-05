#include<glad/glad.h>
#include<glfw/glfw3.h>
#include<iostream>

int g_windowSizeX = 800;
int g_windowSizeY = 800;

void glfwindowSizeCallback(GLFWwindow* window, int width, int height) {
    g_windowSizeX = width;
    g_windowSizeY = height;
    glViewport(0, 0, g_windowSizeX, g_windowSizeY);
}
void glfwKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mode) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GL_TRUE);
}
};
int main() {
    // ������������� ��������� glfw � ��������� ������ ������ opengl(4.6)
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    //�������� ����
    GLFWwindow* window = glfwCreateWindow(g_windowSizeX, g_windowSizeY, "blabla", NULL, NULL);
    if (!window) {
        std::cout << "Fail, but dont give up anyway!!!" << std::endl;
        glfwTerminate();
        return -1;
    }
    //
    glfwSetWindowSizeCallback(window, glfwindowSizeCallback);
    glfwSetKeyCallback(window, glfwKeyCallback);
    //������ ��������� ���� �������
    glfwMakeContextCurrent(window);
    //������������� glad
    if (!gladLoadGL()) {
        std::cout << "GLAD error!" << std::endl;
        return -1;
    }
    std::cout << "Render: " << glGetString(GL_RENDERER) << std::endl;
    std::cout << "OpenGL" << GLVersion.major << '.' << GLVersion.minor << glGetString(GL_VERSION) << std::endl;

    glClearColor(0, 1, 0, 1);
// ���� ������ ����
    while (!glfwWindowShouldClose(window)) {
        //���������
        glClear(GL_COLOR_BUFFER_BIT);
        //����� �������
        glfwSwapBuffers(window);
        //��������� glfw ���������� ��� �������
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
    glfwTerminate();
	std::cout << "window is closen" << std::endl;
	return 0;
}