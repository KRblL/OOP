#include "Controller.hpp"

Controller::Controller(Player& ref_player, Field& ref_field):player{ref_player}, field{ref_field}, coordinates{field.getEntry()} {}

void Controller::setCoordinates(int x, int y)
{
    if (field.checkCoordinates(x, y) && field.getCell(x, y).getPassability())
        coordinates = {x, y};
}

std::pair<int, int> Controller::getCoordinates()
{
    return coordinates;
}

void Controller::changeCoordinates(int delta_x, int delta_y)
{
    setCoordinates(coordinates.first + delta_x, coordinates.second + delta_y);
}

void Controller::changeHealth(int delta_hp)
{
    player.setHealth(player.getHealth() + delta_hp);
}

void Controller::changeScore(int delta_pts)
{
    player.setScore(player.getScore() + delta_pts);
}

void Controller::move(Direction step)
{
    switch(step) 
    {
        case Direction::up:
            changeCoordinates(0, 1);
            break;
        case Direction::down:
            changeCoordinates(0, -1);
            break;
        case Direction::left:
            changeCoordinates(-1, 0);
            break;
        case Direction::right:
            changeCoordinates(1, 0);
            break;
    }
}