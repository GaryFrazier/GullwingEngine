#pragma once

enum LOG_LEVEL { INFO, DEBUG, WARNING, ERROR };

void logMessage(const char* message, LOG_LEVEL logLevel = LOG_LEVEL::DEBUG);