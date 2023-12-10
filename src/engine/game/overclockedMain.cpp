#include "overclockedMain.h"
#include <cstdlib>
#include <iostream>
#include <stdexcept>

const uint32_t WIDTH = 800;
const uint32_t HEIGHT = 600;

void OverclockedMain::run() {
    initWindow();
    initVulkan();
    mainLoop();
    cleanup();
}

void OverclockedMain::initWindow() {
    glfwInit();

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    this->window = glfwCreateWindow(WIDTH, HEIGHT, "Overclocked", nullptr, nullptr);
}

void OverclockedMain::initVulkan() {
    uint32_t extensionCount = 0;
    vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);

    std::cout << extensionCount << " extensions supported\n";
}

void OverclockedMain::mainLoop() {
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
    }
}

void OverclockedMain::cleanup() {
    glfwDestroyWindow(window);
    glfwTerminate();
}