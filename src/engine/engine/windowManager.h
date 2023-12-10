#pragma once
#include <GLFW/glfw3.h>

#include "engine/appInfo.h"

class WindowManager {
public:
    void init(AppInfo* appInfo);
    void cleanup();
    bool poll();
private:
    GLFWwindow* window;
};