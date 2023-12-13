#include "ConsoleLogger.hpp"
#include <iostream>

void ConsoleLogger::getLog(const Message &message)
{
    std::cout << message.getMessage();
}
