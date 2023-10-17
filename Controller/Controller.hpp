#ifndef CONTROLLER
#define CONTROLLER

#include "../Player/Player.hpp"
#include "../Field/Field.hpp"

enum class Direction {up, down, left, right};

class Controller
{  
    Player& player;
    Field& field;
    std::pair <int, int> coordinates;

public:
    Controller(Player& ref_player, Field& ref_field);

    void setCoordinates(int x = 0, int y = 0);

    std::pair<int, int> getCoordinates();

    void changeCoordinates(int delta_x = 0, int delta_y = 0);

    void changeHealth(int delta_hp = 0);

    void changeScore(int delta_pts = 0);

    void move(Direction step);
};

#endif