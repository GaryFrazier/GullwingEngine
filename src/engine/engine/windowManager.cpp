#include "windowManager.h"

const uint32_t WIDTH = 800;
const uint32_t HEIGHT = 600;

void WindowManager::init(AppInfo* appInfo) {
    glfwInit();

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    this->window = glfwCreateWindow(WIDTH, HEIGHT, appInfo->applicationName, nullptr, nullptr);
}

void WindowManager::cleanup() {
    glfwDestroyWindow(this->window);
    glfwTerminate();
}

// returns true if window should close
bool WindowManager::poll() {
    glfwPollEvents();
    return glfwWindowShouldClose(this->window);
}

