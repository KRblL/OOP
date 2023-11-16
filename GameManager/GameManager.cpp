#include "GameManager.hpp"
#include "../Field/FieldCreator.hpp"
#include "../Player/Player.hpp"
#include "../Controller/Controller.hpp"
//#include "../Input/ConfigReader.hpp"
#include "../Input/CommandReader.hpp"
#include <limits>


void GameManager::startGame()
{
    std::cout << "Welcome to the game!\n";
    ConfigReader file("../Input/config.txt");
    cmd_dict = file.readConfig();
    /*for (const auto& element : cmd_dict)
        std::cout << element.first << "\t" << element.second << std::endl;*/
    int level;
    while (1) {
        std::cout << "Please select the level you want to pass: ";
        std::cin >> level;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (!generationLevel(level))
            std::cout << "You entered the level incorrectly. Try again: ";
    }
}

bool GameManager::generationLevel(int lvl)
{
    switch(lvl)
    {
        case 1:
            startLevel(1);
            break;
        case 2:
            startLevel(2);
            break;
        default:
            return false;
    }
    return true;
}

void GameManager::startLevel(int lvl)   
{
    Player player;
    Field field = FieldCreator().createLevel(lvl);
    Controller controller(player, field);
    //ConfigReader file("../Input/config.txt");
    //std::unordered_map<std::string, char> cmd_dict= file.readConfig();
    

    //вызов функции, в которой считываются и выполняются действия
    gameInProgress(controller);

    while (1) {
        int status = checkStatus(controller);
        if (status == NORMAL_STATUS)
            std::cout << "Do you really want to quit the game?\nTo finish the game, enter q\nTo start a new game, enter r\nIf you enter something else, the game will continue\n";
        else if (status == WIN_STATUS)
            std::cout << "Congratulations! You have passed the level!\nTo exit the game, enter q\nTo start the game again, enter something else\n";
        else
            std::cout << "Unfortunately, you lost\nTo exit the game, enter q\nTo start the game again, enter something else\n";

        char decision;
        std::cin >> decision;
        if (std::cin.peek() != '\n') {
            //throw std::runtime_error("Введено больше одного символа");
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            decision = 0;
        }
        switch (decision)
        {
            case 'q':
                exit(0);
                break;
            case 'r':
                return;
                break;
            default:
                if (status == NORMAL_STATUS)
                    gameInProgress(controller);
                else
                    return;
                break;
        }             
    }
}

int GameManager::checkStatus(Controller& controller)
{
    if (controller.getPlayer().isDead())
        return LOSE_STATUS;
    if (controller.getCoordinates() == controller.getField().getExit())
        return WIN_STATUS;
    return NORMAL_STATUS;
}

void GameManager::gameInProgress(Controller& controller)
{
    CommandReader input;
    char act;

    while (act != cmd_dict["QUIT"])
    {
        act = input.readCommand();
        //std::cout << "GAME IN PROGRESS\n";
        
        if (act == cmd_dict["UP"]) {
            controller.move(Direction::up);
        }

        if (act == cmd_dict["DOWN"]) {
            controller.move(Direction::down);
        }

        if (act == cmd_dict["LEFT"]) {
            controller.move(Direction::left);
        }

        if (act == cmd_dict["RIGHT"]) {
            controller.move(Direction::right);
        }

        if (act != -1) {
            std::cout << act << '\n';
            std::cout << controller.getCoordinates().first << '\t' << controller.getCoordinates().second << '\n';
        }

        if (checkStatus(controller) != NORMAL_STATUS) 
            return;

    }
    //act = 0;
}