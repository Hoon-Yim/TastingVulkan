#pragma once

#include <iostream>
#include <vector>
#include <unordered_set>
#include <vulkan/vulkan.h>

#include "VeWindow.h"

namespace ve
{
    class VeDevice
    {
    private:
        VkInstance mInstance;
        VkDebugUtilsMessengerEXT mDebugMessenger;

        const std::vector<const char*> mValidationLayers { "VK_LAYER_KHRONOS_validation" };

    private:
        void createInstance();
        void setupDebugMessenger();

    // helper functions
    private:
        std::vector<const char*> getRequiredExtensions();
        void hasGlfwRequiredInstanceExtensions();
        bool checkValidationLayerSupport();
        void populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo);

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