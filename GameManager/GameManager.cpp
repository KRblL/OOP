#include "GameManager.hpp"
#include "../Field/FieldCreator.hpp"
#include "../Player/Player.hpp"
#include "../Controller/Controller.hpp"
//#include "../Input/ConfigReader.hpp"
#include "../Input/ICommandReader.hpp"
#include "../Logging/ConsoleLogger.hpp"
#include "../Logging/FileLogger.hpp"
#include "../Logging/MessageNewGame.hpp"
#include "../Logging/MessageCommandKey.hpp"
#include "../Logging/MessageLose.hpp"
#include "../Logging/MessageWin.hpp"
#include "../Logging/MessageUnknownKey.hpp"



#include <limits>
//#include <curses.h>

GameManager::GameManager(ICommandReader &inp_reader, ConfigReader &conf_reader)
    : input_reader{inp_reader}, cmd_dict{conf_reader.readConfig()},
      controller{player, field}, status{NORMAL_STATUS} {}

void GameManager::startGame()
{
    //std::cout << "Welcome to the game!\n";
    notifyObserver(ViewState::StartGame);
    need_logging();
    int level;
    while (status != EXIT_STATUS) {
        std::cout << status << '\n';
        notifyObserver(ViewState::ChooseLevel);
        //std::cout << "Please select the level you want to pass: ";
        std::cin >> level;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (!generationLevel(level))
            notifyObserver(ViewState::IncorrectLevel);
            //std::cout << "You entered the level incorrectly. Try again: ";
    }
    std::cout << status << '\n';
}

void GameManager::need_logging()
{
    //std::cout << "Where do you want to receive logs?\n1 - console 2 - file 3 - both\n";
    int log_opt;
    while(1) {
        notifyObserver(ViewState::LoggingSelection);
        std::cin >> log_opt;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch(log_opt)
        {
            case 1:
                // add console logger
                loggers.push_back(new ConsoleLogger);
                return;
            case 2:
                loggers.push_back(new FileLogger);
                // add file logger
                return;
            case 3:
                // add console and file logger
                loggers.push_back(new ConsoleLogger);
                loggers.push_back(new FileLogger);
                return;
            default:
                // repeat input log_opt
                notifyObserver(ViewState::IncorrectLoggingSelection);
                break;
        }
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
    status = NORMAL_STATUS;
    controller.setHealth();
    controller.setScore();
    field = FieldCreator().createLevel(lvl);
    std::pair<int, int> start_coordinates = field.getEntry();
    controller.setCoordinates(start_coordinates.first, start_coordinates.second);
    
    sendLog(MessageNewGame(field.getSize(), field.getEntry()));

    //вызов функции, в которой считываются и выполняются действия
    gameInProgress();
    //char trash;
    //while (trash != -1) trash = input_reader.readCommand();
    //flushinp();
    

    while (1) {
        //int status = checkStatus();
        if (status == NORMAL_STATUS) {
            notifyObserver(ViewState::Menu);
            //std::cout << "Do you really want to quit the game?\nTo finish the game, enter q\nTo start a new game, enter r\nIf you enter something else, the game will continue\n";
        }
        else if (status == WIN_STATUS) {
            notifyObserver(ViewState::Win);
            sendLog(MessageWin(player.getHealth(), player.getScore()));
            //std::cout << "Congratulations! You have passed the level!\nTo exit the game, enter q\nTo start the game again, enter something else\n";
        }
        else if (status == LOSE_STATUS) { 
            notifyObserver(ViewState::Lose);
            sendLog(MessageLose(controller.getCoordinates()));
            //std::cout << "Unfortunately, you lost\nTo exit the game, enter q\nTo start the game again, enter something else\n";
        }

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
                //exit(0);
                status = EXIT_STATUS;
                return;
                break;
            case 'r':
                status = NORMAL_STATUS;
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
        return status = LOSE_STATUS;
    if (controller.getCoordinates() == controller.getField().getExit())
        return status = WIN_STATUS;
    return status = NORMAL_STATUS;
}

void GameManager::gameInProgress()
{
    //CommandReader input;
    //flushinp();
    char act;
    notifyObserver(ViewState::GameProcess);

    while(1) //while (act != cmd_dict["QUIT"])
    {
        act = input_reader.readCommand();
        //std::cout << "GAME IN PROGRESS\n";
        if (act != -1) {
            if (act == cmd_dict["QUIT"]) {
                sendLog(MessageCommandKey(act, "QUIT"));
                //status = EXIT_STATUS;
                return;
            }
            
            else if (act == cmd_dict["UP"]) {
                sendLog(MessageCommandKey(act, "UP"));
                controller.move(Direction::up);
            }

            else if (act == cmd_dict["DOWN"]) {
                sendLog(MessageCommandKey(act, "DOWN"));
                controller.move(Direction::down);
            }

            else if (act == cmd_dict["LEFT"]) {
                sendLog(MessageCommandKey(act, "LEFT"));
                controller.move(Direction::left);
            }

            else if (act == cmd_dict["RIGHT"]) {
                sendLog(MessageCommandKey(act, "RIGHT"));
                controller.move(Direction::right);
            }

            else {
                sendLog(MessageUnknownKey(act));
            }
            checkStatus();
            if (status != NORMAL_STATUS)
                return;
            notifyObserver(ViewState::GameProcess);
        }

        /*if (act != -1) {
            if (checkStatus() != NORMAL_STATUS)
                return;
            notifyObserver(ViewState::GameProcess);
            //std::cout << act << '\n';
            //std::cout << controller.getCoordinates().first << '\t' << controller.getCoordinates().second << '\n';
        }*/
    }
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

void GameManager::sendLog(const Message &message)
{
    for (Logger *logger : loggers)
        logger->getLog(message);
}

GameManager::~GameManager()
{
    if (!loggers.empty()) {
        for (int i = 0; i < loggers.size(); i++) 
            delete loggers[i];
        loggers.clear();
    }
}