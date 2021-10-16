#include "VeDevice.h"

namespace ve
{
    static VKAPI_ATTR VkBool32 VKAPI_CALL DebugCallback(
            VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
            VkDebugUtilsMessageTypeFlagsEXT messegeType,
            const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
            void* pUserdata)
    {
        std::cerr << "validation layer: " << pCallbackData->pMessage << '\n';
        return VK_FALSE;
    }

    VkResult CreateDebugUtilsMessengerEXT(
            VkInstance instance,
            const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo,
            const VkAllocationCallbacks* pAllocator,
            VkDebugUtilsMessengerEXT* pDebugMessenger)
    {
        auto func = (PFN_vkCreateDebugUtilsMessengerEXT) vkGetInstanceProcAddr(instance, "vkCreateDebugUtilsMessengerEXT");

        if (func != nullptr) { return func(instance, pCreateInfo, pAllocator, pDebugMessenger); }
        else { return VK_ERROR_EXTENSION_NOT_PRESENT; }
    }

    void DestroyDebugUtilsMessengerEXT(
            VkInstance instance,
            VkDebugUtilsMessengerEXT debugMessenger,
            const VkAllocationCallbacks* pAllocator)
    {
        auto func = (PFN_vkDestroyDebugUtilsMessengerEXT) vkGetInstanceProcAddr(instance, "vkDestroyDebugUtilsMessengerEXT");
        if (func != nullptr) { func(instance, debugMessenger, pAllocator); }
    }

    // helper..
    std::vector<const char *> VeDevice::getRequiredExtensions()
    {
        uint32_t glfwExtensionCount = 0;
        const char** glfwExtensions;
        glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

        std::vector<const char*> extensions(glfwExtensions, glfwExtensions + glfwExtensionCount);

        if (enabledValidationLayer) { extensions.push_back(VK_EXT_DEBUG_UTILS_EXTENSION_NAME); }

        return extensions;
    }

    void VeDevice::hasGlfwRequiredInstanceExtensions()
    {
        uint32_t availableExtensionCount = 0;
        vkEnumerateInstanceExtensionProperties(nullptr, &availableExtensionCount, nullptr);
        std::vector<VkExtensionProperties> availableExtensions(availableExtensionCount);
        vkEnumerateInstanceExtensionProperties(nullptr, &availableExtensionCount, availableExtensions.data());

        std::cout << "Available Extensions\n";
        std::unordered_set<std::string> available;
        for (const VkExtensionProperties& extension : availableExtensions)
        {
            std::cout << '\t' << extension.extensionName << '\n';
            available.insert(extension.extensionName);
        }

        std::cout << "Required Extensions\n";
        std::vector<const char*> requiredExtentions = getRequiredExtensions();
        for (const char* extension : requiredExtentions)
        {
            std::cout << '\t' << extension << '\n';
            if (available.find(extension) == available.end())
            {
                throw std::runtime_error("missing required GLFW extension!");
            }
        }
    }

    bool VeDevice::checkValidationLayerSupport()
    {
        uint32_t layerCount = 0;
        vkEnumerateInstanceLayerProperties(&layerCount, nullptr);
        std::vector<VkLayerProperties> layers(layerCount);
        vkEnumerateInstanceLayerProperties(&layerCount, layers.data());

        for (const char* layerName : mValidationLayers)
        {
            bool layerFound = false;

            for (const VkLayerProperties& layer : layers)
            {
                if (strcmp(layer.layerName, layerName) == 0)
                {
                    layerFound = true;
                    break;
                }
            }

            if (!layerFound) { return false; }
        }

        return true;
    }

    void VeDevice::populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo)
    {
        createInfo.sType = VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT;
        createInfo.messageSeverity =
                VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT |
                VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT |
                VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT;
        createInfo.messageType =
                VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT |
                VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT |
                VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT;
        createInfo.pfnUserCallback = DebugCallback;
        createInfo.pUserData = nullptr;
    }
    // helper

    // private..
    void VeDevice::createInstance()
    {
        if (enabledValidationLayer && !checkValidationLayerSupport())
        {
            throw std::runtime_error("debug mode is on, but no available layer..");
        }

        VkApplicationInfo appInfo{};
        appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
        appInfo.pApplicationName = "TastingVulkan";
        appInfo.pEngineName = "No Engine";
        appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
        appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
        appInfo.apiVersion = VK_API_VERSION_1_0;

        const std::vector<const char*> extensions = getRequiredExtensions();
        VkInstanceCreateInfo instanceCreateInfo{};
        VkDebugUtilsMessengerCreateInfoEXT debugCreateInfo{};

        instanceCreateInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
        instanceCreateInfo.pApplicationInfo = &appInfo;
        instanceCreateInfo.enabledExtensionCount = static_cast<uint32_t>(extensions.size());
        instanceCreateInfo.ppEnabledExtensionNames = extensions.data();
        if (enabledValidationLayer)
        {
            instanceCreateInfo.enabledLayerCount = static_cast<uint32_t>(mValidationLayers.size());
            instanceCreateInfo.ppEnabledLayerNames = mValidationLayers.data();

            populateDebugMessengerCreateInfo(debugCreateInfo);
            instanceCreateInfo.pNext = &debugCreateInfo;
        }
        else
        {
            instanceCreateInfo.enabledLayerCount = 0;
        }

        if (vkCreateInstance(&instanceCreateInfo, nullptr, &mInstance) != VK_SUCCESS)
        {
            throw std::runtime_error("failed to create Instance!");
        }

        hasGlfwRequiredInstanceExtensions();
    }

    void VeDevice::setupDebugMessenger()
    {
        if (!enabledValidationLayer) { return; }

        VkDebugUtilsMessengerCreateInfoEXT createInfo{};
        populateDebugMessengerCreateInfo(createInfo);

        if (CreateDebugUtilsMessengerEXT(mInstance, &createInfo, nullptr, &mDebugMessenger) != VK_SUCCESS)
        {
            throw std::runtime_error("failed to set up debug messenger!");
        }
    }
    // private

    // public..
    VeDevice::VeDevice()
    {
        createInstance();
        setupDebugMessenger();
    }

    VeDevice::~VeDevice()
    {
        if (enabledValidationLayer) { DestroyDebugUtilsMessengerEXT(mInstance, mDebugMessenger, nullptr); }
        vkDestroyInstance(mInstance, nullptr);
    }
    // public
}