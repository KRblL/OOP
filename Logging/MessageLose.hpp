#ifndef MESSAGE_LOSE
#define MESSAGE_LOSE

#include "IMessage.hpp"

class MessageLose : public Message
{
    std::pair<int, int> coordinates;
public:
    MessageLose(std::pair<int, int> coordinates);
    std::string getMessage() const override;
};

#endif