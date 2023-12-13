#ifndef MESSAGE_UNKNOWN_KEY
#define MESSAGE_UNKNOWN_KEY

#include "IMessage.hpp"

class MessageUnknownKey : public Message
{
    char key;
public:
    MessageUnknownKey(char key);
    std::string getMessage() const override;
};

#endif