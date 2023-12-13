#include "MessageCommandKey.hpp"

MessageCommandKey::MessageCommandKey(char key, std::string command) : key{key}, command{command} {}

std::string MessageCommandKey::getMessage() const
{
    return "The key '" + std::string{key} + "' was entered and the '" + command + "' command worked\n";
}