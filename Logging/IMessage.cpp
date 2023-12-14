#include "IMessage.hpp"

std::ostream& operator<<(std::ostream &os, const Message &message)
{
    return os << message.getMessage();
}