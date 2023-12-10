#pragma once

#include "appInfo.h"

// todo: add settings to use other apis
#define USE_VULKAN
#ifdef USE_VULKAN
#define GLFW_INCLUDE_VULKAN
#include <vulkan/vulkan.h>
#endif

class GraphicsApiManager {
public:
    void init(AppInfo* appInfo);
    void cleanup();
private:
#ifdef USE_VULKAN
    VkInstance instance;
#endif // USE_VULKAN
   
    void createInstance(AppInfo* appInfo);
};