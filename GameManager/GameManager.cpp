#include "GameManager.hpp"
#include "../Field/FieldCreator.hpp"
#include "../Player/Player.hpp"
#include "../Controller/Controller.hpp"
//#include "../Input/ConfigReader.hpp"
#include "../Input/ICommandReader.hpp"
#include <limits>
//#include <curses.h>

GameManager::GameManager(ICommandReader &inp_reader, ConfigReader &conf_reader)
    : input_reader{inp_reader}, cmd_dict{conf_reader.readConfig()},
      controller{player, field} {}

void GameManager::startGame()
{
    //std::cout << "Welcome to the game!\n";
    notifyObserver(ViewState::StartGame);
    //ConfigReader file("../Input/config.txt");
    //cmd_dict = file.readConfig();
    /*for (const auto& element : cmd_dict)
        std::cout << element.first << "\t" << element.second << std::endl;*/
    int level;
    while (1) {
        notifyObserver(ViewState::ChooseLevel);
        //std::cout << "Please select the level you want to pass: ";
        std::cin >> level;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (!generationLevel(level))
            notifyObserver(ViewState::IncorrectLevel);
            //std::cout << "You entered the level incorrectly. Try again: ";
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
    controller.setHealth();
    controller.setScore();
    field = FieldCreator().createLevel(lvl);
    std::pair<int, int> start_coordinates = field.getEntry();
    controller.setCoordinates(start_coordinates.first, start_coordinates.second);
    //std::cout << controller.getCoordinates().first << "\t" << controller.getCoordinates().second << '\n';
    //Controller controller(player, field);
    //ConfigReader file("../Input/config.txt");
    //std::unordered_map<std::string, char> cmd_dict= file.readConfig();
    

    //вызов функции, в которой считываются и выполняются действия
    gameInProgress();
    //char trash;
    //while (trash != -1) trash = input_reader.readCommand();
    //flushinp();
    

    while (1) {
        int status = checkStatus();
        if (status == NORMAL_STATUS)
            notifyObserver(ViewState::Menu);
            //std::cout << "Do you really want to quit the game?\nTo finish the game, enter q\nTo start a new game, enter r\nIf you enter something else, the game will continue\n";
        else if (status == WIN_STATUS)
            notifyObserver(ViewState::Win);
            //std::cout << "Congratulations! You have passed the level!\nTo exit the game, enter q\nTo start the game again, enter something else\n";
        else
            notifyObserver(ViewState::Lose);
            //std::cout << "Unfortunately, you lost\nTo exit the game, enter q\nTo start the game again, enter something else\n";

        char decision;
        std::cin >> decision;
        if (std::cin.peek() != '\n') {
            //throw std::runtime_error("Введено больше одного символа");
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            decision = 0;       //game will continue
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
                    gameInProgress();
                else
                    return;
                break;
        }             
    }
}

int GameManager::checkStatus()
{
    if (controller.getPlayer().isDead())
        return LOSE_STATUS;
    if (controller.getCoordinates() == controller.getField().getExit())
        return WIN_STATUS;
    return NORMAL_STATUS;
}

void GameManager::gameInProgress()
{
    //CommandReader input;
    //flushinp();
    char act;
    notifyObserver(ViewState::GameProcess);

    while (act != cmd_dict["QUIT"])
    {
        act = input_reader.readCommand();
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
            if (checkStatus() != NORMAL_STATUS)
                return;
            notifyObserver(ViewState::GameProcess);
            /*std::cout << act << '\n';
            std::cout << controller.getCoordinates().first << '\t' << controller.getCoordinates().second << '\n';*/
        }
    }
    //act = 0;
}

Controller& GameManager::getController()
{
    return controller;
}

void GameManager::addObserver(Observer *observer)
{
    observers.push_back(observer);
}

void GameManager::removeObserver(Observer *observer)
{
    observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
}

void GameManager::notifyObserver(ViewState view_state)
{
    for (Observer *observer : observers)
        observer->update(view_state);
}