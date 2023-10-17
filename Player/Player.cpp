#include "Player.hpp"
        
bool Player::checkOption(int value)
{
    return value >= MIN_VAL && value <= MAX_VAL;
}

Player::Player(int hp, int points)
{
    if (!checkOption(hp) || !checkOption(points))           
        throw std::invalid_argument("Incorrect arguments!\n");
    health = hp;
    score = points;
}

int Player::getHealth()
{
    return health;
} 

int Player::getScore()
{
    return score;
}

void Player::setHealth(int value)
{
    if (!checkOption(value))
        throw std::invalid_argument("Health should be from 0 to 100!\n");
    health = value;
}

void Player::setScore(int value)
{
    if (!checkOption(value))
        throw std::invalid_argument("Score should be from 0 to 100!\n");
    score = value;
}