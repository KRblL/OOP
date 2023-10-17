#ifndef IEVENT
#define IEVENT

class IEvent
{
public:
    virtual void activationEvent() = 0; // pure virtual method
    virtual IEvent* clone() = 0;    // pure virtual method
};

#endif