#ifndef MESSAGE_NEW_GAME
#define MESSAGE_NEW_GAME

#include "IMessage.hpp"

class MessageNewGame : public Message
{
    std::pair<int, int> field_size;
    std::pair<int, int> start;
public:
    MessageNewGame(std::pair<int, int> field_size, std::pair<int, int> start);
    std::string getMessage() const override;
};

#endif