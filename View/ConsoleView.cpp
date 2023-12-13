#include "ConsoleView.hpp"
#include "../Event/HealEvent.hpp"
#include "../Event/TeleportEvent.hpp"
#include "../Event/DamageEvent.hpp"
#include "../Event/ScoreEvent.hpp"
#include <iostream>
//#include <iomanip>
//#include <functional>
#include <typeinfo>

ConsoleView::ConsoleView(GameManager &game) : game{game}, game_observer{new GameObserver(game, *this)} {}

ConsoleView::~ConsoleView()
{
    delete game_observer;
}

void ConsoleView::update()
{
    //system("clear");
    displayPlayer();
    std::cout << "-------------------\n";
    displayField();
}

void ConsoleView::displayStartGame()
{
    std::cout << "Welcome to the game!\n";
}

void ConsoleView::displayLoggingSelection()
{
    std::cout << "Where do you want to receive logs?\n1 - console\n2 - file\n3 - console and file\n";
}

void ConsoleView::displayIncorrectLoggingSelection()
{
    std::cout << "You entered an incorrect value, try again\n";
}

void ConsoleView::displayChooseLevel()
{
    std::cout << "Please select the level you want to pass: ";
}

void ConsoleView::displayIncorrectLevel()
{
    std::cout << "You entered the level incorrectly. Try again: ";
}

void ConsoleView::displayMenu()
{
    std::cout << "Do you really want to quit the game?\nTo finish the game, enter q\nTo start a new game, enter r\nIf you enter something else, the game will continue\n";
}

void ConsoleView::displayWin()
{
    update();
    std::cout << "Congratulations! You have passed the level!\nTo exit the game, enter q\nTo start the game again, enter something else\n";
}

void ConsoleView::displayLose()
{
    update();
    std::cout << "Unfortunately, you lost\nTo exit the game, enter q\nTo start the game again, enter something else\n";
}

void ConsoleView::displayPlayer()
{
    std::cout << "HEALTH: " << game.getController().getHealth() << '\n';
    std::cout << "SCORE: " << game.getController().getScore() << '\n';
}

void ConsoleView::displayField()
{
    Controller cntrl = game.getController();
   // std::cout << cntrl.getCoordinates().first << "\t" << cntrl.getCoordinates().second << '\n';
    for (int y = cntrl.getField().getSize().second - 1; y > -1; y--) {
        for (int x = 0; x < cntrl.getField().getSize().first; x++) {
            if (x == cntrl.getCoordinates().first && y == cntrl.getCoordinates().second)
                std::cout << "P ";
            else if (x == cntrl.getField().getEntry().first && y == cntrl.getField().getEntry().second)
                std::cout << "s ";
            else if (x == cntrl.getField().getExit().first && y == cntrl.getField().getExit().second)
                std::cout << "f ";
            else if (cntrl.getField().getCell(x, y).getEvent() && typeid(*(cntrl.getField().getCell(x, y).getEvent())) == typeid(HealEvent)) 
                std::cout << "+ ";
            else if (cntrl.getField().getCell(x, y).getEvent() && typeid(*(cntrl.getField().getCell(x, y).getEvent())) == typeid(ScoreEvent)) 
                std::cout << "$ ";
            else if (cntrl.getField().getCell(x, y).getEvent() && typeid(*(cntrl.getField().getCell(x, y).getEvent())) == typeid(TeleportEvent)) 
                std::cout << "@ ";
            else if (cntrl.getField().getCell(x, y).getEvent() && typeid(*(cntrl.getField().getCell(x, y).getEvent())) == typeid(DamageEvent)) 
                std::cout << "x ";
            else if (cntrl.getField().getCell(x, y).getPassability())
                std::cout << ". ";
            else 
                std::cout << "# ";
        }
        std::cout << '\n';
    }
}