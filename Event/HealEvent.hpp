#ifndef HEAL_EVENT
#define HEAL_EVENT

#include "IEvent.hpp"

#define DEFAULT_HEAL 10

class HealEvent: public IEvent
{
    int heal;
public:
    HealEvent(int heal = DEFAULT_HEAL);

    void activationEvent(Controller& controller) override;

    HealEvent* clone() override;
};

#endif