#ifndef MESSAGE_COMMAND_KEY
#define MESSAGE_COMMAND_KEY

#include "IMessage.hpp"

class MessageCommandKey : public Message
{
    char key;
    std::string command;
public:
    MessageCommandKey(char key, std::string command);
    std::string getMessage() const override;
};

#endif