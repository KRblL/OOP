#ifndef TELEPORT_EVENT
#define TELEPORT_EVENT

#include "IEvent.hpp"
#include <iostream>

class TeleportEvent: public IEvent
{
    std::pair<int, int> coordinates;
    //int use_flag = 0;
public:
    TeleportEvent(int x, int y);

    void activationEvent(Controller& controller) override;
    
    TeleportEvent* clone() override;
};

#endif