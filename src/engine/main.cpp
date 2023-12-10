#include "game/overclockedMain.h"
#include <iostream>
#include <stdexcept>

#include "engine/appInfo.h"

int main() {
    OverclockedMain app;
    AppInfo appInfo{};
    appInfo.applicationName = "Overclocked";

    try {
        app.run(&appInfo);
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}