#include "ScoreEvent.hpp"
#include "../Controller/Controller.hpp"
#include "../Player/Player.hpp"
#include "../Field/Cell.hpp"
#include "../Field/Field.hpp"

ScoreEvent::ScoreEvent(int bonus):bonus{bonus >= 0 ? bonus : -bonus} {} 

void ScoreEvent::activationEvent(Controller& controller)
{
    Player& player = controller.getPlayer();
    player.setScore(player.getScore() + bonus);
    std::pair <int, int> cur_cell_coordinates = controller.getCoordinates();
    controller.getField().getCell(cur_cell_coordinates.first, cur_cell_coordinates.second) = Cell(true, nullptr);

}

ScoreEvent* ScoreEvent::clone()
{
    return new ScoreEvent(*this);
}