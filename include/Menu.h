#include "../include/TicTacToe.h"
#include "../include/Helper.h"
#include <iostream>
#include <limits>

#ifndef MENU_H
#define MENU_H

class App
{
private:
    Helper h;
    void ui();
    void menu();
    void gameChoice(int);

public:
    App();
};

#endif
