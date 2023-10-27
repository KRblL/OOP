#ifndef SCORE_EVENT
#define SCORE_EVENT

#include "IEvent.hpp"

#define DEFAULT_BONUS 10

class ScoreEvent: public IEvent
{
    int bonus;
public:
    ScoreEvent(int bonus = DEFAULT_BONUS);
    
    void activationEvent(Controller& controller) override;
    
    ScoreEvent* clone() override;
};

#endif