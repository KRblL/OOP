#include "Player/Player.hpp"
#include "Controller/Controller.hpp"
#include "Field/Cell.hpp"
#include "Field/Field.hpp"
#include "Event/IEvent.hpp"
#include "Event/DamageEvent.hpp"
#include "Event/HealEvent.hpp"
#include "Event/ScoreEvent.hpp"
#include "Event/TeleportEvent.hpp"
#include "Field/FieldCreator.hpp"

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
    /*Player player;
    Field field(10, 15);
    field.setPassability(5, 6, false);
    field.setEntry(5, 5);*/
    /*Field copy_field;
    copy_field = Field(12, 10);
    std::pair <int, int> field_size = copy_field.getSize();
    std::pair <int, int> exit = copy_field.getExit();
    std::pair <int, int> entry = copy_field.getEntry();
    std::cout << "size: " << field_size.first << '\t' << field_size.second << '\n';
    std::cout << "start: " << entry.first << '\t' << entry.second << '\n';
    std::cout << "finish: " << exit.first << '\t' << exit.second << '\n';*/

    //std::cout << field.getCell(5, 6).getPassability() << '\n';

    /*Controller controller(player, field);
    std::pair <int, int> field_size = field.getSize();
    std::pair <int, int> exit = field.getExit();
    std::pair <int, int> entry = field.getEntry();
    //field.setPassability(6, 7, 0);
    std::cout << field.getCell(5, 6).getPassability() << '\n';
    std::cout << "size: " << field_size.first << '\t' << field_size.second << '\n';
    std::cout << "start: " << entry.first << '\t' << entry.second << '\n';
    std::cout << "finish: " << exit.first << '\t' << exit.second << '\n';
    std::pair <int, int> crds1 = controller.getCoordinates();
    std::cout << "coordinates before " << crds1.first << '\t' << crds1.second << '\n';
    controller.move(Direction::up);
    std::pair <int, int> crds2 = controller.getCoordinates();
    std::cout << "coordinates after " << crds2.first << '\t' << crds2.second << '\n';*/

    // Level_1
    /* Player player;
    FieldCreator field_creator;
    Field field = field_creator.createLevel_1();
    //field.FieldView();
    Controller controller(player, field);

    std::pair <int, int> coordinates_before = controller.getCoordinates();
    std::cout << "Coordinates before: " << coordinates_before.first << '\t' <<coordinates_before.second << '\n';
    std::cout << "Score before: " << player.getScore() << '\n';
    controller.move(Direction::right);
    controller.move(Direction::right);
    std::pair <int, int> coordinates_after_teleport1 = controller.getCoordinates();
    std::cout << "Coordinates after: " << coordinates_after_teleport1.first << '\t' <<coordinates_after_teleport1.second << '\n';
    std::cout << "Score after first bonus: " << player.getScore() << "\n\n";

    std::cout << "Health before damage: " << player.getHealth() << '\n';
    controller.move(Direction::right);
    std::cout << "Health after damage: " << player.getHealth() << "\n\n";

    //controller.move(Direction::right);
    //std::cout << controller.getCoordinates().first << '\t' << controller.getCoordinates().second << '\n';

    controller.move(Direction::left);
    controller.move(Direction::up);
    std::cout << "Health after heal: " << player.getHealth() << '\n';

    controller.move(Direction::up);
    controller.move(Direction::right);
    std::cout << "Health after damage: " << player.getHealth() << "\n\n";

    controller.move(Direction::right);
    controller.move(Direction::right);
    controller.move(Direction::right);
    std::pair <int, int> coordinates_after_teleport2 = controller.getCoordinates();
    std::cout << "Coordinates after: " << coordinates_after_teleport2.first << '\t' <<coordinates_after_teleport2.second << '\n';
    std::cout << "Score after second bonus: " << player.getScore() << "\n";

    controller.move(Direction::right);
    std::cout << "Health (no damage at the trap location): " << player.getHealth() << "\n\n";

    for (size_t i = 0; i < 3; i++) {
        controller.move(Direction::right);
    }
    controller.move(Direction::up);
    std::cout << std::boolalpha << "Is the player dead? " << player.isDead() << '\n';*/

    //Level_2
    Player player;
    FieldCreator creator;
    Field field = creator.createLevel_2();
    //field.FieldView();
    Controller controller(player, field);
    std::pair <int, int> coordinates_before = controller.getCoordinates();
    std::cout << "Coordinates before: " << coordinates_before.first << '\t' <<coordinates_before.second << '\n';
    std::cout << "Score before: " << player.getScore() << '\n';
    std::cout << "Health before damage: " << player.getHealth() << "\n\n";

    controller.move(Direction::down);
    controller.move(Direction::down);
    std::pair <int, int> coordinates_after_teleport1 = controller.getCoordinates();
    std::cout << "Coordinates after: " << coordinates_after_teleport1.first << '\t' <<coordinates_after_teleport1.second << '\n';
    std::cout << "Health after damage: " << player.getHealth() << "\n\n";

    for (size_t x = 5; x > 2; x--) {
        controller.move(Direction::left);
    }
    controller.move(Direction::down);
    std::cout << controller.getCoordinates().first << '\t' << controller.getCoordinates().second << '\n';
    controller.move(Direction::down);
    std::pair <int, int> coordinates_after_teleport2 = controller.getCoordinates();
    std::cout << "Coordinates after: " << coordinates_after_teleport2.first << '\t' <<coordinates_after_teleport2.second << '\n';
    std::cout << "Health (no damage at the trap location) : " << player.getHealth() << "\n\n";

    controller.move(Direction::left);
    controller.move(Direction::left);
    /*controller.move(Direction::left);
    std::cout << controller.getCoordinates().first << '\t' << controller.getCoordinates().second << '\n';
    for (size_t y = 9; y > 4; y--) {
        controller.move(Direction::down);
    }
    std::cout << controller.getCoordinates().first << '\t' << controller.getCoordinates().second << '\n';
     std::cout << "Health: " << player.getHealth() << "\n\n";*/
    for (int y = 9; y >= 0; y--) {
        controller.move(Direction::down);
    }
    std::cout << controller.getCoordinates().first << '\t' << controller.getCoordinates().second << '\n';
    std::cout << "Health after heal: " << player.getHealth() << "\n\n";
    for (int x = 3; x <= 9; x++) {
        controller.move(Direction::right);
    }
    std::cout << controller.getCoordinates().first << '\t' << controller.getCoordinates().second << '\n';






    try
    {

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