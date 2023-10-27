#ifndef DAMAGE_EVENT
#define DAMAGE_EVENT

#include "IEvent.hpp"

#define DEFAULT_DAMAGE 10

class DamageEvent: public IEvent
{
    int damage;
public:
    DamageEvent(int damage = DEFAULT_DAMAGE);

    void activationEvent(Controller& controller) override;
    
    DamageEvent* clone() override;
};

#endif