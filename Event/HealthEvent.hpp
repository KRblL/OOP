#ifndef HEALTH_EVENT
#define HEALTH_EVENT

#include "IEvent.hpp"

class HealthEvent: public IEvent
{
    void activationEvent() override;
    
    HealthEvent* clone() override;
};

#endif