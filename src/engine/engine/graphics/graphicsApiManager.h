#pragma once
#include "../appInfo.h"

#include <vector>

#define GLFW_INCLUDE_VULKAN
#include <vulkan/vulkan.h>

class GraphicsApiManager {
public:
    void init(AppInfo* appInfo);
    void cleanup();
private:
    VkInstance instance;
    VkDebugUtilsMessengerEXT debugMessenger;
   
    void createInstance(AppInfo* appInfo);
    void setupDebugMessenger();
    bool checkValidationLayerSupport();

    std::vector<const char*> getRequiredExtensions();
    VkResult CreateDebugUtilsMessengerEXT(VkInstance instance, const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDebugUtilsMessengerEXT* pDebugMessenger);
    void populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo);
    void DestroyDebugUtilsMessengerEXT(VkInstance instance, VkDebugUtilsMessengerEXT debugMessenger, const VkAllocationCallbacks* pAllocator);
};