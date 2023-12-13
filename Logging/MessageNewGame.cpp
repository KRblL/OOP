#include "MessageNewGame.hpp"

MessageNewGame::MessageNewGame(std::pair<int, int> field_size, std::pair<int, int> start) : field_size{field_size}, start{start} {}

std::string MessageNewGame::getMessage() const
{
    return "A new game has been launched\tField size: " + std::to_string(field_size.first) + ", " + std::to_string(field_size.second) + 
    "\tPlayer's starting position: " + std::to_string(start.first) + ", " + std::to_string(start.second) + "\n";
}