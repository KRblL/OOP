#include "FieldCreator.hpp"
#include "Cell.hpp"
#include "../Event/HealEvent.hpp"
#include "../Event/DamageEvent.hpp"
#include "../Event/TeleportEvent.hpp"
#include "../Event/ScoreEvent.hpp"

Field FieldCreator::createLevel_1()
{
    Field field(5, 5);
    field.setEntry(0, 0);
    field.setExit(4, 4);
    field.getCell(1, 1) = Cell(true, new DamageEvent(50));
    field.getCell(1, 3) = Cell(true, new DamageEvent(50));
    field.getCell(0, 2) = Cell(true, new HealEvent(50));
    field.getCell(1, 0) = Cell(true, new ScoreEvent(50));
    field.getCell(3, 3) = Cell(true, new ScoreEvent(50));
    field.getCell(2, 0) = Cell(true, new TeleportEvent(0, 1));
    field.getCell(4, 3) = Cell(true, new TeleportEvent(0, 3));
    field.setAreaPassability(2, 1, 3, 2, false);
    return field;  
}

Field FieldCreator::createLevel_2()
{
    Field field(10, 10);
    field.setEntry(0, 9);
    field.setExit(9, 0);
    field.setAreaPassability(4, 4, 9, 7, false);
    field.getCell(5, 9) = Cell(true, new DamageEvent(99));
    for (size_t x = 0; x < 3; x++) {
        field.getCell(x, 7) = Cell(true, new TeleportEvent(5, 9));
        field.getCell(x, 4) = Cell(true, new DamageEvent(1));
    }
    field.getCell(3, 7) = Cell(true, new ScoreEvent(99));
    field.getCell(3, 4) = Cell(true, new HealEvent(100));
    field.getCell(8, 0) = Cell(true, new ScoreEvent(1));
    return field;
}
