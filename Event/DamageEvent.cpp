#include "DamageEvent.hpp"
#include "../Controller/Controller.hpp"
#include "../Player/Player.hpp"
#include "../Field/Cell.hpp"
#include "../Field/Field.hpp"

DamageEvent::DamageEvent(int damage):damage{damage >= 0 ? damage : -damage} {}

void DamageEvent::activationEvent(Controller& controller)
{
    Player& player = controller.getPlayer();
    player.setHealth(player.getHealth() - damage);
    std::pair <int, int> cur_cell_coordinates = controller.getCoordinates();
    Cell& cur_cell = controller.getField().getCell(cur_cell_coordinates.first, cur_cell_coordinates.second);
    cur_cell = Cell(true, nullptr);
    if (player.isDead())  //check death
        std::cout << "Game over: you're dead!\n";
}

DamageEvent* DamageEvent::clone()
{
    return new DamageEvent(*this);
}