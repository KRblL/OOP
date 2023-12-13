#include "MessageLose.hpp"

MessageLose::MessageLose(std::pair<int, int> coordinates) : coordinates{coordinates} {}

std::string MessageLose::getMessage() const
{
    return "DEFEAT!\tCoordinates: " + std::to_string(coordinates.first) + ", " + std::to_string(coordinates.second) + "\n";
}