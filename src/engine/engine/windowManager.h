#pragma once

#define VK_USE_PLATFORM_WIN32_KHR
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#define GLFW_EXPOSE_NATIVE_WIN32
#include <GLFW/glfw3native.h>


#include "engine/appInfo.h"

class WindowManager {
public:
    void init(AppInfo* appInfo);
    void cleanup();
    bool poll();
    GLFWwindow* window;
};