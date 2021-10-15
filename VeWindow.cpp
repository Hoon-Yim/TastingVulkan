#include "VeWindow.h"

namespace ve
{
    VeWindow::VeWindow(int width, int height, const char* title)
    {
        glfwInit();
        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
        mWindow = glfwCreateWindow(width, height, title, nullptr, nullptr);
    }

    VeWindow::~VeWindow()
    {
        glfwTerminate();
        glfwDestroyWindow(mWindow);
    }

    bool VeWindow::ShouldClose() { return glfwWindowShouldClose(mWindow); }
}