#define _CRT_SECURE_NO_WARNINGS
#include "PodyLogger.h"

std::string PodyLogger::getCurrentTime() const
{  
    // Получаем текущее время
    auto now = std::chrono::system_clock::now();
    std::time_t time = std::chrono::system_clock::to_time_t(now);
    std::tm localTime = *std::localtime(&time);
    auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()) % 1000;


    // Форматируем время в строку "[HH:MM:SS]"
    std::stringstream ss;
    ss << "[" << std::setw(2) << std::setfill('0') << localTime.tm_hour << ":"
        << std::setw(2) << std::setfill('0') << localTime.tm_min << ":"
        << std::setw(2) << std::setfill('0') << localTime.tm_sec << "."
        << std::setw(3) << std::setfill('0') << milliseconds.count() << "]";
   ;

    return ss.str();
    
}

void PodyLogger::log(LogLevel level, const std::string& message) const
{
    std::cout 
        << getLogLevelColorCode(level) 
        << std::setw(10) << std::left << getLogLevelString(level) << " "
        << std::setw(10) << getCurrentTime() << " "
        << message << std::endl;
    resetColor();
}

std::string PodyLogger::getLogLevelString(LogLevel level) const
{
    // Преобразование уровня логирования в строковый формат
    switch (level) {
    case LogLevel::DEBUG:
        return "[DEBUG]";
    case LogLevel::INFO:
        return "[INFO]";
    case LogLevel::WARNING:
        return "[WARNING]";
    case LogLevel::ERROR:
        return "[ERROR]";
    default:
        return "[UNKNOWN]";
    }
}

std::string PodyLogger::getLogLevelColorCode(LogLevel level) const
{
    switch (level) {
    case LogLevel::DEBUG:
        return "\033[1;34m";  // Ярко-синий
    case LogLevel::INFO:
        return "\033[1;32m";  // Ярко-зеленый
    case LogLevel::WARNING:
        return "\033[1;33m";  // Желтый
    case LogLevel::ERROR:
        return "\033[1;31m";  // Ярко-красный
    default:
        return "\033[0m";  // Сброс цвета (белый)
    }
}

void PodyLogger::resetColor() const
{
    std::cout << "\033[0m";
}



