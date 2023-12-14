#pragma once
#include <GLFW/glfw3.h>

#include "engine/appInfo.h"
#include "engine/windowManager.h"
#include "engine/graphics/graphicsApiManager.h"

class OverclockedMain {
public:
    void run(AppInfo* appInfo);

private:
    WindowManager* windowManager;
    GraphicsApiManager* graphicsApiManager;

    void initWindow(AppInfo* appInfo);
    void initGraphicsApi(AppInfo* appInfo);
    void mainLoop();
    void cleanup();
};