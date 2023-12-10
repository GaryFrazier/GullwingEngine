#include "logger.h"

#include <iostream>

const char* green = "\033[1;32m";
const char* yellow = "\033[1;33m";
const char* red = "\033[1;31m";
const char* resetColor = "\033[0m";

#ifdef LOG_LEVEL_DEBUG
int minLogLevel = 1;
#elifdef LOG_LEVEL_WARNING
int minLogLevel = 2;
#elifdef LOG_LEVEL_ERROR
int minLogLevel = 3;
#else
int minLogLevel = 0;
#endif

void logMessage(const char* message, LOG_LEVEL logLevel) {
	const char* colorCode = ""; // none

	// set color code for message, none for info
	switch(logLevel) {
		case LOG_LEVEL::DEBUG:
			colorCode = green;
			break;
		case LOG_LEVEL::WARNING:
			colorCode = yellow;
			break;
		case LOG_LEVEL::ERROR:
			colorCode = red;
			break;

	}

	if (logLevel >= minLogLevel) {
		std::cout << colorCode << message << resetColor << "\n";
	}
}