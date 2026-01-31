#include "../include/Menu.h"

using namespace std;

// ------------------------------------------------------------
// ------------ Constructor Function
App::App()
{
    ui();
}

// ------------------------------------------------------------
// ------------ Menu Function
void App::menu()
{
    cout << B_BLUE << "   ======================================" << "\n";
    cout << "   ||" << B_YELLOW << "        V-ARCADE MAIN MENU      " << B_BLUE << "  ||\n";
    cout << "   ======================================" << RESET << "\n";

    cout << "\n";
    cout << "       " << RED << "[ 0 ]   EXIT APPLICATION" << RESET << "\n\n";

    // TIER 1: THE BASICS
    cout << "      " << B_WHITE << "---------- QUICK GAMES ----------" << RESET << "\n";
    cout << "       " << B_CYAN << "[ 1 ]   NUMBER GUESSING" << RESET << "\n";
    cout << "       " << B_MAGENTA << "[ 2 ]   ROCK PAPER SCISSORS" << RESET << "\n";
    cout << "       " << B_YELLOW << "[ 3 ]   DIE BETTING" << RESET << "\n";

    // TIER 2: CLASSIC LOGIC
    cout << "\n      " << B_WHITE << "-------- CLASSIC PUZZLES --------" << RESET << "\n";
    cout << "       " << B_GREEN << "[ 4 ]   TIC TAC TOE" << RESET << "\n";
    cout << "       " << B_CYAN << "[ 5 ]   HANGMAN" << RESET << "\n";
    cout << "       " << B_BLUE << "[ 6 ]   CONNECT FOUR" << RESET << "\n";

    // TIER 3: ADVANCED / SYSTEM
    cout << "\n      " << B_WHITE << "---------- CHALLENGING ----------" << RESET << "\n";
    cout << "       " << B_YELLOW << "[ 7 ]   SNAKE GAME" << RESET << "\n";
    cout << "       " << RED << "[ 8 ]   BATTLESHIP" << RESET << "\n";
    cout << "       " << B_GREEN << "[ 9 ]   MINESWEEPER" << RESET << "\n";

    cout << "\n"
         << B_BLUE << "   Select your challenge: " << RESET;
}

// ------------------------------------------------------------
// ------------ Game Selection Function
void App::gameChoice(int choice)
{
    switch (choice)
    {
    case 0:
        cout << B_RED
             << "   ======================================\n"
             << "   ||    EXITING PROGRAM... GOODBYE!   ||\n"
             << "   ======================================\n"
             << RESET;
        break;

    case 4:
    {
        TicTacToe game;
        game.play();
    }
    break;

    default:
        cout << "\n";
        cout << B_RED << "   [!] INVALID CHOICE!" << RESET << YELLOW << " Please try again." << RESET << "\n";
        cout << "\n";
        cout << "   Press Enter to continue...";
        cin.ignore();
        cin.get();
        break;
    }
}

// ------------------------------------------------------------
// ------------ UI Function
void App::ui()
{
    int choice;

    do
    {
        h.clearScreen();
        menu();

        if (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            choice = -1;
        }

        gameChoice(choice);

    } while (choice != 0);
}
