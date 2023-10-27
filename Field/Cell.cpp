#include "Cell.hpp"


Cell::Cell(bool passable , IEvent* event):passability(passable), event{event}{} 

Cell::Cell(const Cell &other):passability{other.passability}, event{other.event ? other.event->clone() : nullptr} {}      

Cell& Cell::operator = (const Cell &other)
{
    if (this != &other) {
        Cell temp(other);
        std::swap(passability, temp.passability);
        std::swap(event, temp.event);
    }
    return *this;
}

Cell::Cell(Cell &&other):passability{true}, event{nullptr}
{
    std::swap(passability, other.passability);
    std::swap(event, other.event);
}

Cell& Cell::operator = (Cell &&other)
{
    if (this != &other) {
        std::swap(passability, other.passability);
        std::swap(event, other.event);
    }
    return *this;
}

bool Cell::getPassability() const
{
    return passability;
}

void Cell::setPassability(bool value)
{
    passability = value;
}

IEvent* Cell::getEvent() const
{
    return event;
}

Cell::~Cell()
{
    delete event;
}
