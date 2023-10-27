#ifndef IEVENT
#define IEVENT

class Controller;

class IEvent
{
public:
    virtual void activationEvent(Controller& controller) = 0; // pure virtual method
    virtual IEvent* clone() = 0;    // pure virtual method
    virtual ~IEvent() = 0;          // pure virtual method
};

#endif