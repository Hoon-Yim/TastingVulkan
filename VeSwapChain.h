#pragma once

#include "VeDevice.h"

namespace ve
{
    class VeSwapChain
    {
    private:
        VeDevice&  mDevice;
        VkSwapchainKHR mSwapChain;
        VkExtent2D mWindowExtent;

        VkFormat mSwapChainImageFormat;
        VkExtent2D mSwapChainExtent;

    // helper functions
    private:
        VkSurfaceFormatKHR chooseSwapSurfaceFormat(const std::vector<VkSurfaceFormatKHR>& availableFormats);
        VkPresentModeKHR chooseSwapPresentMode(const std::vector<VkPresentModeKHR>& availableModes);
        VkExtent2D chooseSwapExtent(const VkSurfaceCapabilitiesKHR& capabilities);

    private:
        void createSwapChain();

    public:
        VeSwapChain(VeDevice& device, VkExtent2D windowExtent);
        ~VeSwapChain();
    };
}