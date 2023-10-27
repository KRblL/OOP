#include "Controller.hpp"
#include "../Field/Cell.hpp"
#include "../Field/Field.hpp"
#include "../Event/IEvent.hpp"

Controller::Controller(Player& ref_player, Field& ref_field):player{ref_player}, field{ref_field}, coordinates{field.getEntry()} {}

std::pair<int, int> Controller::getCoordinates()
{
    return coordinates;
}

Player& Controller::getPlayer()
{
    return player;
}

Field& Controller::getField()
{
    return field;
}

void Controller::move(Direction step)
{
    std::pair<int, int> coordinates_before = coordinates; 
    switch(step) 
    {
        case Direction::up:
            coordinates.second += 1;
            break;
        case Direction::down:
            coordinates.second -= 1;
            break;
        case Direction::left:
            coordinates.first -= 1;
            break;
        case Direction::right:
            coordinates.first += 1;
            break;
    }
    if(!(field.checkCoordinates(coordinates.first, coordinates.second) && field.getCell(coordinates.first, coordinates.second).getPassability()))
        coordinates = coordinates_before;
    else {
        IEvent* cur_event = field.getCell(coordinates.first, coordinates.second).getEvent();
        if (cur_event)                                          // check nullptr
            cur_event->activationEvent(*this);
    }
}

void Controller::setCoordinates(int x, int y)
{
    if (field.checkCoordinates(x, y) && field.getCell(x, y).getPassability())
        coordinates = {x, y};
        IEvent* cur_event = field.getCell(x, y).getEvent();
        if (cur_event)                                          // check nullptr
            cur_event->activationEvent(*this);

}



/*void Controller::changeCoordinates(int delta_x, int delta_y)
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
}*/