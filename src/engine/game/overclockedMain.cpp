#include "overclockedMain.h"
#include "engine/util/logger.h"

void OverclockedMain::run(AppInfo* appInfo) {
    initWindow(appInfo);
    initGraphicsApi(appInfo);
    mainLoop();
    cleanup();
}

void OverclockedMain::initWindow(AppInfo* appInfo) {
    logMessage("Initializing window...");

    WindowManager winManager;
    winManager.init(appInfo);
    this->windowManager = winManager;
}

void OverclockedMain::initGraphicsApi(AppInfo* appInfo) {
    logMessage("Initializing graphics api...");

    GraphicsApiManager apiManager;
    apiManager.init(appInfo);
    this->graphicsApiManager = apiManager;
}

void OverclockedMain::mainLoop() {
    bool exit = false;

    while (!exit) {
        exit = this->windowManager.poll();
    }
}

void OverclockedMain::cleanup() {
    this->graphicsApiManager.cleanup();
    this->windowManager.cleanup();
}