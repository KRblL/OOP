#ifndef CONSOLE_VIEW
#define CONSOLE_VIEW

#include "IView.hpp"
#include "../GameManager/GameManager.hpp"
#include "GameObserver.hpp"

class ConsoleView: public IView
{
    GameManager &game;
    GameObserver *game_observer;
public:
    ConsoleView(GameManager &game);
    ~ConsoleView();
    void update() override;
    void displayStartGame() override;
    void displayChooseLevel() override;
    void displayIncorrectLevel() override;
    void displayMenu() override;
    void displayWin() override;
    void displayLose() override;
    void displayField() override;
    void displayPlayer() override;
};

#endif