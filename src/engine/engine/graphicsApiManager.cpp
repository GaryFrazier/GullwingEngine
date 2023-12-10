#include "graphicsApiManager.h"
#include "util/logger.h"

#include <GLFW/glfw3.h>
#include <stdexcept>
#include <vector>

void GraphicsApiManager::init(AppInfo* appInfo) {
	this->createInstance(appInfo);
}


void GraphicsApiManager::createInstance(AppInfo* appInfo) {
#ifdef USE_VULKAN
    VkApplicationInfo vkAppInfo{};
    vkAppInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    vkAppInfo.pApplicationName = appInfo->applicationName;
    vkAppInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
    vkAppInfo.pEngineName = "Gullwing";
    vkAppInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
    vkAppInfo.apiVersion = VK_API_VERSION_1_0;

    VkInstanceCreateInfo createInfo{};
    createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    createInfo.pApplicationInfo = &vkAppInfo;

    uint32_t glfwExtensionCount = 0;
    const char** glfwExtensions;
    glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

    createInfo.enabledExtensionCount = glfwExtensionCount;
    createInfo.ppEnabledExtensionNames = glfwExtensions;

    createInfo.enabledLayerCount = 0;

    // check extension info, not used atm
    uint32_t extensionCount = 0;
    vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);
    std::vector<VkExtensionProperties> extensions(extensionCount);

    vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, extensions.data());

    logMessage("available vulkan extensions:", LOG_LEVEL::INFO);

    for (const auto& extension : extensions) {
        logMessage(extension.extensionName, LOG_LEVEL::INFO);
    }

    if (vkCreateInstance(&createInfo, nullptr, &instance) != VK_SUCCESS) {
        logMessage("failed to create instance!", LOG_LEVEL::ERROR);
        throw std::runtime_error("failed to create instance!");
    }

    logMessage("graphics instance created: VULKAN");
#endif // USE_VULKAN   
}

void GraphicsApiManager::cleanup() {
#ifdef USE_VULKAN
    vkDestroyInstance(this->instance, nullptr);
#endif
}
