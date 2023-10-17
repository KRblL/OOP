#include "Player/Player.hpp"
#include "Controller/Controller.hpp"
#include "Field/Cell.hpp"
#include "Field/Field.hpp"
#include "Event/IEvent.hpp"
#include "Event/HealthEvent.hpp"

int main()
{
//LB1 TESTS
    /*Player player(10, 12);
    player.setHealth(0);
    player.setScore(88);
    std::cout << player.getHealth() << '\t' << player.getScore() << '\n';*/

//LB2 TESTS
    //Cell
    /*Interface *event = new HealthEvent;
    Cell cell1(true, event);
    std::cout << cell1.getPassability() << '\n';
    cell1.setPassability(false);
    std::cout << cell1.getPassability() << '\n';
    
    Cell cell2 = cell1;
    Cell cell3(Cell(false, new HealthEvent));*/

    //Field
    /*Field field(15, 10);
    std::pair <int, int> field_size = field.getSize();
    field.setStart(3, 4);
    field.setFinish(9, 8);
    field.setPassability(5, 5, false);
    std::pair <int, int> entry = field.getStart();
    std::pair <int, int> exit = field.getFinish();
    std::cout << "size: " << field_size.first << '\t' << field_size.second << '\n';
    std::cout << "start: " << entry.first << '\t' << entry.second << '\n';
    std::cout << "finish: " << exit.first << '\t' << exit.second << '\n';
    std::cout << field.getCell(5, 5).getPassability() << '\n';*/

    //Controller
    Player player;
    Field field(10, 10);
    field.setStart(7, 7);
    Controller controller(player, field);
    std::pair <int, int> field_size = field.getSize();
    std::pair <int, int> exit = field.getFinish();
   // field.setStart(5, 5);
    std::pair <int, int> entry = field.getStart();
    field.setPassability(6, 7, 0);
    std::cout << field.getCell(5, 6).getPassability() << '\n';
    std::cout << "size: " << field_size.first << '\t' << field_size.second << '\n';
    std::cout << "start: " << entry.first << '\t' << entry.second << '\n';
    std::cout << "finish: " << exit.first << '\t' << exit.second << '\n';
    std::pair <int, int> crds1 = controller.getCoordinates();
    std::cout << "coordinates before " << crds1.first << '\t' << crds1.second << '\n';
    controller.move(Direction::left);
    std::pair <int, int> crds2 = controller.getCoordinates();
    std::cout << "coordinates after " << crds2.first << '\t' << crds2.second << '\n';






    try
    {
        //Field field(88, -99);
        //Field field(10, 10);
        //field.setStart(10, 8);
        //field.setFinish(5, -2);
        //field.setPassability(5, 10);
        //field.getCell(11, 6);
    }
    catch(std::invalid_argument& err)
    {
        std::cout << err.what();
    }
    catch(std::out_of_range& err)
    {
        std::cout << err.what();
    }
    return 0;
}