#include "Field.hpp"

#define DEF_SIZE 10
#define DEF_START 0 
#define MIN_SIZE 2
#define MAX_SIZE 100

bool Field::checkSize(int width, int height)
{
    return width >= MIN_SIZE && width <= MAX_SIZE && height >= MIN_SIZE && height <= MAX_SIZE;
}

bool Field::checkCoordinates(int x, int y) const
{
    return x >= 0 && x < size.first && y >= 0 && y < size.second;
}

Field::Field(int width, int height)  
{
    if (!checkSize(width, height))  
        throw std::invalid_argument("Invalid size of playing field!\n");
    size = {width, height};
    entry = {DEF_ENTRY, DEF_ENTRY};
    exit = {width - 1, height - 1};
    cell_arr = new Cell* [width];
    for (size_t x = 0; x < width; x++) {      //++x
        cell_arr[x] = new Cell [height];
    }
}

std::pair<int, int> Field::getSize()
{
    return size;
}

std::pair<int, int> Field::getEntry()
{
    return entry;
}

std::pair<int, int> Field::getExit()
{
    return exit;
}

void Field::setEntry(int x_start, int y_start)
{
    if(!checkCoordinates(x_start, y_start))
        throw std::invalid_argument("Entry coordinates should be inside the playing field!\n");
    if (x_start != exit.first || y_start != exit.second)
        entry = {x_start, y_start};
}

void Field::setExit(int x_finish, int y_finish)
{
    if(!checkCoordinates(x_finish, y_finish))
        throw std::invalid_argument("Exit coordinates should be inside the playing field!\n");
    if (x_finish != entry.first || y_finish != entry.second)
        exit = {x_finish, y_finish};
}

const Cell& Field::getCell(int x, int y) const
{
    if (!checkCoordinates(x, y))
        throw std::out_of_range("Invalid coordinates\nThere is no cell with such coordinates\n");
    return cell_arr[x][y];
}

void Field::setPassability(int x, int y, bool value)
{
    if (!checkCoordinates(x, y))
        throw std::out_of_range("Invalid coordinates\nThere is no cell with such coordinates\n");
    cell_arr[x][y].setPassability(value);
}

Field::~Field()
{
    for (size_t x = 0; x < size.first; x++) {
        delete [] cell_arr[x];
    }
    delete [] cell_arr;
}
