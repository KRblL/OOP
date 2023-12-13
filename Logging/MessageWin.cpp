#include "MessageWin.hpp"

MessageWin::MessageWin(int health, int score) : health{health}, score {score} {}

std::string MessageWin::getMessage() const
{
    return "VICTORY!\tHealth: " + std::to_string(health) + "\tScore: " + std::to_string(score) + "\n";
}