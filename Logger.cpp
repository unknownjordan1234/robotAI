// Logger.cpp
#include "Logger.h"

Logger::Logger(const std::string& filename) {
    logFile.open(filename, std::ios::app);
    if (!logFile) {
        std::cerr << "Could not open log file!" << std::endl;
    }
}

void Logger::log(const std::string& message) {
    if (logFile) {
        logFile << message << std::endl;
    }
}

Logger::~Logger() {
    if (logFile.is_open()) {
        logFile.close();
    }
}
