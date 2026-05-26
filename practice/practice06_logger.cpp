#include <iostream>
#include <string>

// Practice 06: Simple logger
//
// Task:
// Complete Logger.
// It should print different prefixes for different log levels.
//
// Advanced:
// Add a current log level.
// Only print messages whose level is greater than or equal to current level.

enum class LogLevel
{
    Info,
    Warning,
    Error
};

class Logger
{
public:
    void Log(LogLevel level, const std::string& message)
    {
        // TODO: Print:
        // [Info] message
        // [Warning] message
        // [Error] message
    }
};

int main()
{
    Logger logger;

    logger.Log(LogLevel::Info, "Program started");
    logger.Log(LogLevel::Warning, "Low memory");
    logger.Log(LogLevel::Error, "File not found");

    std::cin.get();
}
