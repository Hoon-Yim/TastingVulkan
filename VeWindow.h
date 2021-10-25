#pragma once

#include <string>

#include <vulkan/vulkan.h>
#include <GLFW/glfw3.h>

namespace ve
{
    class VeWindow
    {
    private:
        GLFWwindow* mWindow;
        const int mWIDTH;
        const int mHEIGHT;

    public:
        VeWindow(int width, int height, const char* title);
        ~VeWindow();

        bool ShouldClose();
        void CreateWindowSurface(VkInstance instance, VkSurfaceKHR* surface);

        VkExtent2D GetExtent()
        {
            return {static_cast<uint32_t>(mWIDTH), static_cast<uint32_t>(mHEIGHT)};
        }
    };
}