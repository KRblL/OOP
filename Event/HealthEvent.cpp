#include "HealthEvent.hpp"

void HealthEvent::activationEvent()
{
    // health event
}

HealthEvent* HealthEvent::clone()
{
    return new HealthEvent(*this);
}