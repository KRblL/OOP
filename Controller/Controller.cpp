#include "Controller.hpp"
#include "../Field/Cell.hpp"
#include "../Field/Field.hpp"
#include "../Event/IEvent.hpp"
#include "../Player/Player.hpp"

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
        Cell& cur_cell = field.getCell(coordinates.first, coordinates.second);
        IEvent* cur_event = cur_cell.getEvent();
        if (cur_event) {                                          // check nullptr
            cur_event->activationEvent(*this);
            cur_cell = Cell(true, nullptr);
        }
    }
}

void Controller::setCoordinates(int x, int y)
{
    if (field.checkCoordinates(x, y) && field.getCell(x, y).getPassability())
        coordinates = {x, y};
        //IEvent* cur_event = field.getCell(x, y).getEvent();
        Cell& cur_cell = field.getCell(x, y);
        IEvent* cur_event = cur_cell.getEvent();
        if (cur_event) {                                          // check nullptr
            cur_event->activationEvent(*this);
            cur_cell = Cell(true, nullptr);
        }
}



/*void Controller::changeCoordinates(int delta_x, int delta_y)
{
    setCoordinates(coordinates.first + delta_x, coordinates.second + delta_y);
}*/

void Controller::setHealth(int value)
{
    player.setHealth(value);
}

void Controller::setScore(int value)
{
    player.setScore(value);
}

int Controller::getHealth()
{
    return player.getHealth();
}

int Controller::getScore()
{
    return player.getScore();
}