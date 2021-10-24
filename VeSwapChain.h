#pragma once

#include "VeDevice.h"

namespace ve
{
    class VeSwapChain
    {
    private:
        VkExtent2D windowExtent;

    // helper functions
    private:
        VkSurfaceFormatKHR chooseSwapSupportFormat(const std::vector<VkSurfaceFormatKHR>& availableFormats);
        VkPresentModeKHR chooseSwapPresentMode(const std::vector<VkPresentModeKHR>& availableModes);
        VkExtent2D chooseSwapExtent(const VkSurfaceCapabilitiesKHR& capabilities);

    public:
        VeSwapChain(VeDevice& device, VkExtent2D windowExtent);
    };
}