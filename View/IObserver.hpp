#ifndef IOBSERVER
#define IOBSERVER
#include "ViewState.hpp"

class Observer
{
public:
    virtual void update(ViewState view_state) = 0;
    virtual ~Observer() {};
};

#endif