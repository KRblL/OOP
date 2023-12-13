#ifndef MESSAGE_WIN
#define MESSAGE_WIN

#include "IMessage.hpp"

class MessageWin : public Message
{
    int health;
    int score;
public:
    MessageWin(int health, int score);
    std::string getMessage() const override;
};

#endif