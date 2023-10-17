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
    
    bool checkOption(int value); // функция проверки валидности полей здоровья или очков

public:
    Player(int hp = DEF_HEALTH, int points = DEF_SCORE);

    int getHealth();

    int getScore();

    void setHealth(int value = MIN_VAL);

    void setScore(int value = MIN_VAL);
};

#endif