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
#include "GameManager/GameManager.hpp"
#include "Input/CommandReader.hpp"
#include "View/ConsoleView.hpp"

int main()
{
    CommandReader input_reader;
    ConfigReader conf_reader("../Input/config.txt");
    GameManager game(input_reader, conf_reader);
    ConsoleView displayer(game);
    game.startGame();
    return 0;
    




    /*Player player;
    Field field(5, 5);
    field.getCell(1, 0) = Cell(true, new TeleportEvent(0, 0));
    Controller controller(player, field);
    controller.move(Direction::right);
    std::cout << controller.getCoordinates().first << '\t' << controller.getCoordinates().second << '\n';
    controller.move(Direction::right);
    std::cout << controller.getCoordinates().first << '\t' << controller.getCoordinates().second << '\n';*/

    //check DamageEvent
    /*Player player;
    Field field(5, 5);
    field.getCell(1, 0) = Cell(true, new DamageEvent(50));
    Controller controller(player, field);
    std::cout << controller.getCoordinates().first << '\t' << controller.getCoordinates().second << '\n';
    std::cout << "Health: " << player.getHealth() << "\n\n";
    controller.move(Direction::right);
    std::cout << controller.getCoordinates().first << '\t' << controller.getCoordinates().second << '\n';
    std::cout << "Health: " << player.getHealth() << '\n';
    controller.move(Direction::right);
    std::cout << controller.getCoordinates().first << '\t' << controller.getCoordinates().second << '\n';
    controller.move(Direction::left);
    std::cout << controller.getCoordinates().first << '\t' << controller.getCoordinates().second << '\n';
    std::cout << "Health: " << player.getHealth() << '\n';*/

    //checkHealEvent
    /*Player player;
    Field field(5, 5);
    field.getCell(1, 0) = Cell(true, new DamageEvent(50));
    field.getCell(2, 0) = Cell(true, new HealEvent(30));
    Controller controller(player, field);
    std::cout << controller.getCoordinates().first << '\t' << controller.getCoordinates().second << '\n';
    std::cout << "Health: " << player.getHealth() << "\n\n";
    controller.move(Direction::right);
    std::cout << controller.getCoordinates().first << '\t' << controller.getCoordinates().second << '\n';
    std::cout << "Health: " << player.getHealth() << "\n\n";
    controller.move(Direction::right);
    std::cout << controller.getCoordinates().first << '\t' << controller.getCoordinates().second << '\n';
    std::cout << "Health: " << player.getHealth() << "\n\n";
    controller.move(Direction::left);
    std::cout << controller.getCoordinates().first << '\t' << controller.getCoordinates().second << '\n';
    std::cout << "Health: " << player.getHealth() << "\n\n";
    controller.move(Direction::right);
    std::cout << controller.getCoordinates().first << '\t' << controller.getCoordinates().second << '\n';
    std::cout << "Health: " << player.getHealth() << '\n';*/

    //checkScoreEvent
    /*Player player;
    Field field(5, 5);
    field.getCell(0, 1) = Cell(true, new ScoreEvent(25));
    Controller controller(player, field);
    std::cout << controller.getCoordinates().first << '\t' << controller.getCoordinates().second << '\n';
    std::cout << "Score: " << player.getScore() << "\n\n";
    controller.move(Direction::up);
    std::cout << controller.getCoordinates().first << '\t' << controller.getCoordinates().second << '\n';
    std::cout << "Score: " << player.getScore() << "\n\n";
    controller.move(Direction::down);
    std::cout << controller.getCoordinates().first << '\t' << controller.getCoordinates().second << '\n';
    std::cout << "Score: " << player.getScore() << "\n\n";
    controller.move(Direction::up);
    std::cout << controller.getCoordinates().first << '\t' << controller.getCoordinates().second << '\n';
    std::cout << "Score: " << player.getScore() << "\n\n";*/

    //checkTeleportEvent
    /*Player player;
    Field field(5, 5);
    field.getCell(0, 1) = Cell(true, new TeleportEvent(3, 3));
    field.getCell(3, 3) = Cell(true, new TeleportEvent(0, 3));
    field.getCell(0, 3) = Cell(true, new TeleportEvent(4, 4));
    Controller controller(player, field);
    std::cout << controller.getCoordinates().first << '\t' << controller.getCoordinates().second << "\n\n";
    controller.move(Direction::up);
    std::cout << controller.getCoordinates().first << '\t' << controller.getCoordinates().second << "\n\n";*/




    // Level_1
    /*Player player;
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
    /*Player player;
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
    controller.move(Direction::left);*/
    /*controller.move(Direction::left);
    std::cout << controller.getCoordinates().first << '\t' << controller.getCoordinates().second << '\n';
    for (size_t y = 9; y > 4; y--) {
        controller.move(Direction::down);
    }
    std::cout << controller.getCoordinates().first << '\t' << controller.getCoordinates().second << '\n';
     std::cout << "Health: " << player.getHealth() << "\n\n";*/
    /*for (int y = 9; y >= 0; y--) {
        controller.move(Direction::down);
    }
    std::cout << controller.getCoordinates().first << '\t' << controller.getCoordinates().second << '\n';
    std::cout << "Health after heal: " << player.getHealth() << "\n\n";
    for (int x = 3; x <= 9; x++) {
        controller.move(Direction::right);
    }
    std::cout << controller.getCoordinates().first << '\t' << controller.getCoordinates().second << '\n';
    std::cout << "Finish Score: " << player.getScore() << '\n';*/
}