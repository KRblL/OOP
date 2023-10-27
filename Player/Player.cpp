#include "Player.hpp"
        
int Player::checkOption(int value)
{
    if (value > MAX_VAL)
        return 1;
    else if (value < MIN_VAL)
        return -1;
    return 0;
}

Player::Player():health{DEF_HEALTH}, score{DEF_SCORE} {}

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
    int flag = checkOption(value);
    if (flag == 1)
        health = MAX_VAL;
    else if (flag == -1)
        health = MIN_VAL;
    else
        health = value;
}

void Player::setScore(int value)
{
    int flag = checkOption(value);
    if (flag == 1)
        score = MAX_VAL;
    else if (flag == -1)
        score = MIN_VAL;
    else
        score = value;
}

bool Player::isDead()
{
    return health <= MIN_VAL;
}