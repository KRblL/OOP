#ifndef GAME
#define GAME

#include "../Input/ConfigReader.hpp"
#include "../Input/ICommandReader.hpp"
#include "../Player/Player.hpp"
#include "../Field/Field.hpp"
#include "../Controller/Controller.hpp"
#include "../View/IObservable.hpp"
#include "../Logging/ILogger.hpp"
#include <iostream>
#define LOSE_STATUS -1
#define NORMAL_STATUS 0
#define WIN_STATUS 1
#define EXIT_STATUS 2   //'q'



class GameManager : public Observable
{
    Player player;
    Field field;
    Controller controller;
    ICommandReader &input_reader;
    std::unordered_map<std::string, char> cmd_dict;
    std::vector<Observer*> observers;
    std::vector<Logger*> loggers;
    void need_logging();
    int checkStatus();
    int status;
public:
    GameManager(ICommandReader &inp_reader, ConfigReader &conf_reader);
    Controller& getController();
    void startGame(); 
    bool generationLevel(int lvl);
    void startLevel(int lvl);
    void gameInProgress();

    void addObserver(Observer *observer) override;
    void removeObserver(Observer *observer) override;
    void notifyObserver(ViewState view_state) override;
    
    void sendLog(const Message &message);
    ~GameManager();
};

#endif