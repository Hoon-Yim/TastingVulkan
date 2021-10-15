#pragma once

#include <string>

#include <GLFW/glfw3.h>

namespace ve
{
    class VeWindow
    {
    private:
        GLFWwindow* mWindow;

    public:
        VeWindow(int width, int height, const char* title);
        ~VeWindow();

        bool ShouldClose();
    };
}