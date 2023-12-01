#ifndef IVIEW
#define IVIEW

class IView
{
public:
    virtual void update() = 0;
    virtual void displayStartGame() = 0;
    virtual void displayChooseLevel() = 0;
    virtual void displayIncorrectLevel() = 0;
    virtual void displayMenu() = 0;
    virtual void displayWin() = 0;
    virtual void displayLose() = 0;
    virtual void displayField() = 0;
    virtual void displayPlayer() = 0;
    virtual ~IView() {};
};

#endif