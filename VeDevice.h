#pragma once

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <optional>
#include <set>
#include <unordered_set>
#include <vector>

#include "VeWindow.h"

namespace ve
{
    struct SwapChainSupportDetails
    {
        VkSurfaceCapabilitiesKHR Capabilities;
        std::vector<VkSurfaceFormatKHR> Formats;
        std::vector<VkPresentModeKHR> PresentModes;
    };

    struct QueueFamilyIndices
    {
        std::optional<uint32_t> GraphicsFamily;
        std::optional<uint32_t> PresentFamily;

        bool IsComplete()
        {
            return GraphicsFamily.has_value() && PresentFamily.has_value();
        }
    };

    class VeDevice
    {
    private:
        VeWindow mWindow;
        VkInstance mInstance;
        VkDebugUtilsMessengerEXT mDebugMessenger;
        VkPhysicalDevice mPhysicalDevice = VK_NULL_HANDLE;
        VkPhysicalDeviceProperties mPhysicalDeviceProperties;

        VkDevice mDevice;
        VkSurfaceKHR mSurface;
        VkQueue mGraphicsQueue;
        VkQueue mPresentQueue;

        const std::vector<const char*> mValidationLayers { "VK_LAYER_KHRONOS_validation" };
        const std::vector<const char*> mDeviceExtensions { VK_KHR_SWAPCHAIN_EXTENSION_NAME };

    // helper functions
    private:
        std::vector<const char*> getRequiredExtensions();
        void hasGlfwRequiredInstanceExtensions();
        bool checkValidationLayerSupport();
        void populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo);
        bool isDeviceSuitable(VkPhysicalDevice device);
        bool checkDeviceExtensionSupport(VkPhysicalDevice device);
        QueueFamilyIndices findQueueFamilies(VkPhysicalDevice physicalDevice);
        SwapChainSupportDetails querySwapChainSupport(VkPhysicalDevice device);

    private:
        void createInstance();
        void setupDebugMessenger();
        void createSurface();
        void pickPhysicalDevice();
        void createLogicalDevice();

    public:
        #ifdef NDEBUG
            const bool enabledValidationLayer = false;
        #else
            const bool enabledValidationLayer = true;
        #endif

        VeDevice(VeWindow& window);
        ~VeDevice();

        VkDevice GetDevice() { return mDevice; }
        QueueFamilyIndices GetQueueFamilies() { return findQueueFamilies(mPhysicalDevice); }
        SwapChainSupportDetails GetSwapChainSupport() { return querySwapChainSupport(mPhysicalDevice); }
        VkSurfaceKHR GetSurface() { return mSurface; }
    };
}