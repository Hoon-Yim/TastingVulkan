#pragma once

#include <iostream>
#include <vector>
#include <unordered_set>
#include <optional>
#include <vulkan/vulkan.h>

#include "VeWindow.h"

namespace ve
{
    struct QueueFamilyIndices
    {
        std::optional<uint32_t> GraphicsFamily;

        bool IsComplete() { return GraphicsFamily.has_value(); }
    };

    class VeDevice
    {
    private:
        VkInstance mInstance;
        VkDebugUtilsMessengerEXT mDebugMessenger;

        VkPhysicalDevice mPhysicalDevice = VK_NULL_HANDLE;
        VkPhysicalDeviceProperties mPhysicalDeviceProperties;
        VkDevice mDevice;
        VkQueue mGraphicsQueue;
        VkQueue mPresentQueue;

        const std::vector<const char*> mValidationLayers { "VK_LAYER_KHRONOS_validation" };

    private:
        void createInstance();
        void setupDebugMessenger();
        void pickPhysicalDevice();
        void createLogicalDevice();

    // helper functions
    private:
        std::vector<const char*> getRequiredExtensions();
        void hasGlfwRequiredInstanceExtensions();
        bool checkValidationLayerSupport();
        void populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo);
        bool isDeviceSuitable(VkPhysicalDevice device);
        QueueFamilyIndices findQueueFamilies(VkPhysicalDevice physicalDevice);

    public:
        #ifdef NDEBUG
            const bool enabledValidationLayer = false;
        #else
            const bool enabledValidationLayer = true;
        #endif

        VeDevice();
        ~VeDevice();
    };
}