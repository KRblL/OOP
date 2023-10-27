#ifndef CELL
#define CELL

#include "../Event/IEvent.hpp"
#include <iostream>

class Cell
{
    bool passability;
    IEvent* event;
    

public:
    Cell(bool passable = true , IEvent* event = nullptr); 
    
    Cell(const Cell &other);  

    Cell& operator = (const Cell &other);

    Cell(Cell &&other);

    Cell& operator = (Cell &&other);

    bool getPassability() const;

    void setPassability(bool value = true);

    IEvent* getEvent() const;

    ~Cell();
};

#endif