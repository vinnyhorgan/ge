#include "Logger.h"

#include <iostream>
#include <string>
#include <chrono>
#include <ctime>

std::vector<LogEntry> Logger::messages;

std::string CurrentDateTimeToString() {
    std::time_t now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    std::string output(30, '\0');
    std::strftime(&output[0], output.size(), "%d-%b-%Y %H:%M:%S", std::localtime(&now));
    return output;
}

void Logger::Log(const std::string& message)
{
    LogEntry entry;
    entry.type = INFO;
    entry.message = "LOG: [" + CurrentDateTimeToString() + "]: " + message;
    messages.push_back(entry);

    std::cout << "\033[32m" << entry.message << "\033[0m" << std::endl;
}

void Logger::Warn(const std::string& message)
{
    LogEntry entry;
    entry.type = WARNING;
    entry.message = "WARN: [" + CurrentDateTimeToString() + "]: " + message;
    messages.push_back(entry);

    std::cout << "\033[33m" << entry.message << "\033[0m" << std::endl;
}

void Logger::Err(const std::string& message)
{
    LogEntry entry;
    entry.type = ERROR;
    entry.message = "ERR: [" + CurrentDateTimeToString() + "]: " + message;
    messages.push_back(entry);

    std::cout << "\033[31m" << entry.message << "\033[0m" <<  std::endl;
}
