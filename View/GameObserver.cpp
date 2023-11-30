#include "GameObserver.hpp"

GameObserver::GameObserver(GameManager &game, IView &view) : game{game}, view{view}
{
    game.addObserver(this);
}

void GameObserver::update(ViewState view_state)
{
    switch(view_state)
    {
        case ViewState::StartGame:
            return view.displayStartGame();
            break;
        case ViewState::ChooseLevel:
            return view.displayChooseLevel();
            break;
        case ViewState::IncorrectLevel:
            return view.displayIncorrectLevel();
        case ViewState::GameProcess:
            return view.update();
            break;
        case ViewState::Menu:
            return view.displayMenu();
            break;
        case ViewState::Win:
            return view.displayWin();
            break;
        case ViewState::Lose:
            return view.displayLose();
            break;
    }
}