#include "VeSwapChain.h"

namespace ve
{
    // helper..
    VkSurfaceFormatKHR VeSwapChain::chooseSwapSupportFormat(const std::vector<VkSurfaceFormatKHR>& availableFormats)
    {
        for (const VkSurfaceFormatKHR& availableFormat : availableFormats)
        {
            if (availableFormat.format == VK_FORMAT_B8G8R8A8_SRGB &&
                availableFormat.colorSpace == VK_COLOR_SPACE_SRGB_NONLINEAR_KHR)
            { return availableFormat; }

            return availableFormats[0];
        }
    }

    VkPresentModeKHR VeSwapChain::chooseSwapPresentMode(const std::vector<VkPresentModeKHR>& availableModes)
    {
        for (const VkPresentModeKHR& availableMode : availableModes)
        {
            if (availableMode == VK_PRESENT_MODE_MAILBOX_KHR) { return availableMode; }
        }

        return VK_PRESENT_MODE_FIFO_KHR;
    }

    VkExtent2D VeSwapChain::chooseSwapExtent(const VkSurfaceCapabilitiesKHR& capabilities)
    {
        if (capabilities.currentExtent.width != UINT32_MAX) { return capabilities.currentExtent; }
        else
        {
            VkExtent2D actualExtent = windowExtent;
            actualExtent.width = std::max(capabilities.minImageExtent.width,
                                 std::min(capabilities.maxImageExtent.width, actualExtent.width));
            actualExtent.height = std::max(capabilities.minImageExtent.height,
                                  std::min(capabilities.maxImageExtent.height, actualExtent.height));

            return actualExtent;
        }
    }
    // helper
}