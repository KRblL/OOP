#ifndef FIELD
#define FIELD

#include "Cell.hpp"
#include <iostream>


#define DEF_SIZE 10
#define DEF_ENTRY 0 
#define MIN_SIZE 2
#define MAX_SIZE 100

class Field
{
    Cell** cell_arr;
    std::pair <int, int> size;
    std::pair <int, int> entry;
    std::pair <int, int> exit;

    bool checkSize(int width, int height);


public:
    Field(int width = DEF_SIZE, int height = DEF_SIZE);      // may be create default constructor without arguments
    
    std::pair<int, int> getSize();

    std::pair<int, int> getEntry();

    std::pair<int, int> getExit();

    void setEntry(int x_start, int y_start);

    void setExit(int x_finish, int y_finish);

    const Cell& getCell(int x = 0, int y = 0) const;

    void setPassability(int x, int y, bool value = true);

    bool checkCoordinates(int x, int y) const;
    
    ~Field();
};

#endif