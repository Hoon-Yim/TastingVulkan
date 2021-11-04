#include "VeSwapChain.h"

namespace ve
{
    // helper..
    VkSurfaceFormatKHR VeSwapChain::chooseSwapSurfaceFormat(const std::vector<VkSurfaceFormatKHR>& availableFormats)
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
            VkExtent2D actualExtent = mWindowExtent;
            actualExtent.width = std::max(capabilities.minImageExtent.width,
                                 std::min(capabilities.maxImageExtent.width, actualExtent.width));
            actualExtent.height = std::max(capabilities.minImageExtent.height,
                                  std::min(capabilities.maxImageExtent.height, actualExtent.height));

            return actualExtent;
        }
    }
    // helper

    // private..
    void VeSwapChain::createSwapChain()
    {
        SwapChainSupportDetails swapChainSupport = mDevice.GetSwapChainSupport();

        VkSurfaceFormatKHR surfaceFormat = chooseSwapSurfaceFormat(swapChainSupport.Formats);
        VkPresentModeKHR presentMode = chooseSwapPresentMode(swapChainSupport.PresentModes);
        VkExtent2D extent = chooseSwapExtent(swapChainSupport.Capabilities);

        uint32_t imageCount = swapChainSupport.Capabilities.minImageCount + 1;
        if (swapChainSupport.Capabilities.maxImageCount > 0 &&
            imageCount > swapChainSupport.Capabilities.maxImageCount)
        {
            imageCount = swapChainSupport.Capabilities.maxImageCount;
        }

        VkSwapchainCreateInfoKHR createInfo{};
        createInfo.sType = VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR;
        createInfo.surface = mDevice.GetSurface();
        createInfo.minImageCount = imageCount;
        createInfo.imageFormat = surfaceFormat.format;
        createInfo.imageColorSpace = surfaceFormat.colorSpace;
        createInfo.imageExtent = extent;
        createInfo.imageArrayLayers = 1;
        createInfo.imageUsage = VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT;

        QueueFamilyIndices indices = mDevice.GetQueueFamilies();
        uint32_t queueFamilyIndices[] = {indices.GraphicsFamily.value(), indices.PresentFamily.value()};

        if (indices.GraphicsFamily != indices.PresentFamily) {
            createInfo.imageSharingMode = VK_SHARING_MODE_CONCURRENT;
            createInfo.queueFamilyIndexCount = 2;
            createInfo.pQueueFamilyIndices = queueFamilyIndices;
        } else {
            createInfo.imageSharingMode = VK_SHARING_MODE_EXCLUSIVE;
            createInfo.queueFamilyIndexCount = 0; // Optional
            createInfo.pQueueFamilyIndices = nullptr; // Optional
        }
        createInfo.preTransform = swapChainSupport.Capabilities.currentTransform;
        createInfo.compositeAlpha = VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR;
        createInfo.presentMode = presentMode;
        createInfo.clipped = VK_TRUE;
        createInfo.oldSwapchain = VK_NULL_HANDLE;

        if (vkCreateSwapchainKHR(mDevice.GetDevice(), &createInfo, nullptr, &mSwapChain) != VK_SUCCESS)
        {
            throw std::runtime_error("failed to create swap chain!");
        }

        vkGetSwapchainImagesKHR(mDevice.GetDevice(), mSwapChain, &imageCount, nullptr);
        mSwapChainImages.resize(imageCount);
        vkGetSwapchainImagesKHR(mDevice.GetDevice(), mSwapChain, &imageCount, mSwapChainImages.data());

        mSwapChainImageFormat = surfaceFormat.format;
        mSwapChainExtent = extent;
    }

    void VeSwapChain::createImageViews()
    {
        mSwapChainImageViews.resize(mSwapChainImages.size());

        for (size_t i = 0; i < mSwapChainImages.size(); i++)
        {
            VkImageViewCreateInfo createInfo{};
            createInfo.sType = VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO;
            createInfo.image = mSwapChainImages[i];
            createInfo.viewType = VK_IMAGE_VIEW_TYPE_2D;
            createInfo.format = mSwapChainImageFormat;
            createInfo.subresourceRange.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
            createInfo.subresourceRange.baseMipLevel = 0;
            createInfo.subresourceRange.levelCount = 1;
            createInfo.subresourceRange.baseArrayLayer = 0;
            createInfo.subresourceRange.layerCount = 1;

            if (vkCreateImageView(mDevice.GetDevice(), &createInfo, nullptr, &mSwapChainImageViews[i]) != VK_SUCCESS)
            {
                throw std::runtime_error("failed to create texture image view!");
            }
        }
    }
    // private

    // public..
    VeSwapChain::VeSwapChain(VeDevice& device, VkExtent2D windowExtent)
        : mDevice{device}, mWindowExtent(windowExtent)
    {
        createSwapChain();
    }

    VeSwapChain::~VeSwapChain()
    {
        for (VkImageView imageView : mSwapChainImageViews)
        {
            vkDestroyImageView(mDevice.GetDevice(), imageView, nullptr);
        }
        mSwapChainImageViews.clear();

        if (mSwapChain != nullptr)
        {
            vkDestroySwapchainKHR(mDevice.GetDevice(), mSwapChain, nullptr);
            mSwapChain = nullptr;
        }
    }

    // public
}