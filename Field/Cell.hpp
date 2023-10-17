#ifndef CELL
#define CELL

#include "../Event/IEvent.hpp"
#include <iostream>

class Cell
{
    bool passability;
    IEvent* event; // указатель на игровое событие (будет реализовано в следующих работах)
    

public:
    Cell(bool passable = true , IEvent *event = nullptr); 
    
    Cell(const Cell &other);  

    Cell& operator = (const Cell &other);

    Cell(Cell &&other);

    Cell& operator = (Cell &&other);

    bool getPassability() const;

    void setPassability(bool value = true);

    ~Cell();
};

#endif