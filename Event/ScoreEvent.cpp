#include "ScoreEvent.hpp"
#include "../Controller/Controller.hpp"
#include "../Player/Player.hpp"
#include "../Field/Cell.hpp"
#include "../Field/Field.hpp"

ScoreEvent::ScoreEvent(int bonus):bonus{bonus} {} 

void ScoreEvent::activationEvent(Controller& controller)
{
    Player& player = controller.getPlayer();
    player.setScore(player.getScore() + bonus);
    std::pair <int, int> cur_cell_coordinates = controller.getCoordinates();
    Cell& cur_cell = controller.getField().getCell(cur_cell_coordinates.first, cur_cell_coordinates.second);
    cur_cell = Cell(true, nullptr);

}

ScoreEvent* ScoreEvent::clone()
{
    return new ScoreEvent(*this);
}