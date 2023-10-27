#ifndef PLAYER
#define PLAYER

#include <iostream>
#define MIN_VAL 0
#define MAX_VAL 100
#define DEF_HEALTH 100
#define DEF_SCORE 0

class Player
{
    int health;
    int score;     // случайное кол-во очков случайным образом разбросаны по полю, игрок получает очки, перейдя в клетку; max 100 очков отражает полноту прохождения уровня
    
    int checkOption(int value); // функция проверки валидности полей здоровья или очков

public:
    Player();

    int getHealth();

    int getScore();

    void setHealth(int value = DEF_HEALTH);

    void setScore(int value = DEF_SCORE);

    bool isDead();
};

#endif