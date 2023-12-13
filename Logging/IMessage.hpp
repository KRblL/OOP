#ifndef IMESSAGE
#define IMESSAGE

#include <string>

class Message
{
public:
    virtual std::string getMessage() const = 0;
};

#endif