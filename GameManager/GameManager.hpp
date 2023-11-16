#ifndef GAME
#define GAME

#include "../Input/ConfigReader.hpp"
#include <iostream>
#define LOSE_STATUS -1
#define NORMAL_STATUS 0
#define WIN_STATUS 1

class Controller;

class GameManager
{
    std::unordered_map<std::string, char> cmd_dict;
public:
    void startGame(); 
    bool generationLevel(int lvl);
    void startLevel(int lvl);
    void gameInProgress(Controller& controller);
    int checkStatus(Controller& controller);
};

#endif