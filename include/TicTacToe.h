#include "../include/Helper.h"
#include "../include/DB.h"
#include "../include/DB.h"
#include <iostream>
#include <fstream>
#include <limits>
#include <string>

#ifndef TICTACTOE_H
#define TICTACTOE_H

// =================================================
// ================== Board Class ==================
// =================================================
class Board
{
private:
    char grid[3][3];

public:
    Board();
    void reset();
    bool isfull();
    char winner();
    bool isOccupied(int);
    void display(int, int);
    void enterChoice(int, char);
};

// =================================================
// ================== TicTacToe  Class ==================
// =================================================
class TicTacToe
{
private:
    DB *gameDB;
    int win = 0;
    int loss = 0;

    Board gameBoard;
    void getScore();
    void setScore();
    void inputMove();
    void getUserChoice();
    void getBotsChoice();
    void showResult();

public:
    TicTacToe();
    void play();
};

#endif