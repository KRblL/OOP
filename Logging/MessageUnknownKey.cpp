#include "MessageUnknownKey.hpp"

MessageUnknownKey::MessageUnknownKey(char key) : key{key} {}

std::string MessageUnknownKey::getMessage() const
{
    return "An unknown key '" + std::string{key} + "' was entered - no command worked\n";
}