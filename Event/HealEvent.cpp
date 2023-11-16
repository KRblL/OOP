#include "HealEvent.hpp"
#include "../Controller/Controller.hpp"
#include "../Player/Player.hpp"
#include "../Field/Cell.hpp"
#include "../Field/Field.hpp"

HealEvent::HealEvent(int heal):heal{heal >= 0 ? heal : -heal} {}

void HealEvent::activationEvent(Controller& controller)
{
    controller.setHealth(controller.getHealth() + heal);
    //std::pair <int, int> cur_cell_coordinates = controller.getCoordinates();
    //controller.getField().getCell(cur_cell_coordinates.first, cur_cell_coordinates.second) = Cell(true, nullptr);
}

HealEvent* HealEvent::clone()
{
    return new HealEvent(*this);
}