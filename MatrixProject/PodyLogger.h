#pragma once
#include <iostream>
#include <iomanip>
#include <chrono>
#include <sstream>

enum class LogLevel {
    DEBUG,
    INFO,
    WARNING,
    ERROR
};

class PodyLogger
{
private:
    std::string getCurrentTime() const;
    std::string getLogLevelString(LogLevel level) const;
    std::string getLogLevelColorCode(LogLevel level) const;
    void resetColor() const;
public:
    void log(LogLevel level, const std::string& message) const; 

};

