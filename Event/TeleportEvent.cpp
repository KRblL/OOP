#include "TeleportEvent.hpp"
#include "../Controller/Controller.hpp"
#include "../Field/Cell.hpp"
#include "../Field/Field.hpp"

TeleportEvent::TeleportEvent(int x, int y):coordinates{x, y} {}

void TeleportEvent::activationEvent(Controller& controller)
{
    if (use_flag == 0) {
        ++use_flag;
        controller.setCoordinates(coordinates.first, coordinates.second);
    }
}

TeleportEvent* TeleportEvent::clone()
{
    return new TeleportEvent(*this);
}