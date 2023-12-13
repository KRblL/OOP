#ifndef CONSOLE_LOGGER
#define CONSOLE_LOGGER

#include "ILogger.hpp"

class ConsoleLogger : public Logger
{
public:
    void getLog(const Message &message) override;
};

#endif