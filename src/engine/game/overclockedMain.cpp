#include "overclockedMain.h"

#include <cstdlib>
#include <iostream>
#include <stdexcept>

void OverclockedMain::run(AppInfo* appInfo) {
    initWindow(appInfo);
    initGraphicsApi(appInfo);
    mainLoop();
    cleanup();
}

void OverclockedMain::initWindow(AppInfo* appInfo) {
    WindowManager winManager;
    winManager.init(appInfo);
    this->windowManager = winManager;
}

void OverclockedMain::initGraphicsApi(AppInfo* appInfo) {
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