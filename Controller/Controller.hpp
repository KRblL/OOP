#ifndef CONTROLLER
#define CONTROLLER

#include "Direction.hpp"
#include <iostream>

class Player;
class Field;

class Controller
{  
    Player& player;
    Field& field;
    std::pair <int, int> coordinates;

public:
    Controller(Player& ref_player, Field& ref_field);

    std::pair<int, int> getCoordinates();

    Player& getPlayer();
    
    Field& getField();

    void move(Direction step);

    void setCoordinates(int x = 0, int y = 0);

    //void changeCoordinates(int delta_x = 0, int delta_y = 0);

    void setHealth(int value = 100);

    void setScore(int value = 0);

    int getHealth();

    int getScore();
};

#endif