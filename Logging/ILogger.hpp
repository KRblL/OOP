#ifndef ILOGGER
#define ILOGGER

#include "IMessage.hpp"

class Logger
{
public:
    virtual void getLog(const Message &message) = 0;
    virtual ~Logger() {}
};

#endif