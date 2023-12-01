#ifndef IOBSERVABLE
#define IOBSERVABLE
#include "IObserver.hpp"

class Observable
{
public:
    virtual void addObserver(Observer *observer) = 0;
    virtual void removeObserver(Observer *observer) = 0;
    virtual void notifyObserver(ViewState view_state) = 0;
    virtual ~Observable() {};
};

#endif