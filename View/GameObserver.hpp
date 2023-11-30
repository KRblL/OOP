#ifndef GAME_OBSERVER
#define GAME_OBSERVER

#include "IObserver.hpp"
#include "IView.hpp"
#include "../GameManager/GameManager.hpp"

class GameObserver: public Observer
{
    GameManager &game;
    IView &view;
public:
    GameObserver(GameManager &game, IView &view);
    void update(ViewState view_state) override;
};

#endif