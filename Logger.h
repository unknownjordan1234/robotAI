// Logger.h
#ifndef LOGGER_H
#define LOGGER_H

#include <fstream>
#include <string>
#include <iostream>

class Logger {
public:
    Logger(const std::string& filename);
    void log(const std::string& message);
    ~Logger();

private:
    std::ofstream logFile;
};

#endif // LOGGER_H
