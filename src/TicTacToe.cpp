#include "../include/TicTacToe.h"

using namespace std;

Helper h;

// =================================================
// ================= Board Methods =================
// =================================================

// ------------ Constructor Function
Board::Board()
{
    reset();
}

// ------------------------------------------------
// ------------ Reset Function
void Board::reset()
{
    int count = 1;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            grid[i][j] = '0' + count++;
        }
    }
}

// ------------------------------------------------
// ------------ Display Function
void Board::display(int win, int loss)
{
    cout << "\n\n";

    cout << "                " << CYAN << "|     |" << RESET << "     \n";
    cout << "           "
         << (grid[0][0] == 'X' ? RED : (grid[0][0] == 'O' ? BLUE : YELLOW)) << "  " << grid[0][0] << "  " << RESET
         << CYAN << "|" << RESET
         << (grid[0][1] == 'X' ? RED : (grid[0][1] == 'O' ? BLUE : YELLOW)) << "  " << grid[0][1] << "  " << RESET
         << CYAN << "|" << RESET
         << (grid[0][2] == 'X' ? RED : (grid[0][2] == 'O' ? BLUE : YELLOW)) << "  " << grid[0][2] << "  " << RESET
         << "\n";
    cout << "           " << CYAN << "_____|_____|_____" << RESET << "\n";

    cout << "                " << CYAN << "|     |" << RESET << "     \n";
    cout << "           "
         << (grid[1][0] == 'X' ? RED : (grid[1][0] == 'O' ? BLUE : YELLOW)) << "  " << grid[1][0] << "  " << RESET
         << CYAN << "|" << RESET
         << (grid[1][1] == 'X' ? RED : (grid[1][1] == 'O' ? BLUE : YELLOW)) << "  " << grid[1][1] << "  " << RESET
         << CYAN << "|" << RESET
         << (grid[1][2] == 'X' ? RED : (grid[1][2] == 'O' ? BLUE : YELLOW)) << "  " << grid[1][2] << "  " << RESET
         << "\n";
    cout << "           " << CYAN << "_____|_____|_____" << RESET << "\n";

    cout << "                " << CYAN << "|     |" << RESET << "     \n";
    cout << "           "
         << (grid[2][0] == 'X' ? RED : (grid[2][0] == 'O' ? BLUE : YELLOW)) << "  " << grid[2][0] << "  " << RESET
         << CYAN << "|" << RESET
         << (grid[2][1] == 'X' ? RED : (grid[2][1] == 'O' ? BLUE : YELLOW)) << "  " << grid[2][1] << "  " << RESET
         << CYAN << "|" << RESET
         << (grid[2][2] == 'X' ? RED : (grid[2][2] == 'O' ? BLUE : YELLOW)) << "  " << grid[2][2] << "  " << RESET
         << "\n";
    cout << "                " << CYAN << "|     |" << RESET << "     \n";

    cout << "\n";
    cout << YELLOW << "=======================================" << RESET << "\n";
    cout << "          " << RESET << "YOU: " << RED << win << RESET << "  ||  " << RESET << "BOT: " << BLUE << loss << RESET << "\n";
    cout << YELLOW << "=======================================" << RESET << "\n";
    cout << "\n";
}

// ------------------------------------------------
// ------------ IsOccupied Function
bool Board::isOccupied(int choice)
{
    int row = (choice - 1) / 3;
    int col = (choice - 1) % 3;

    if (grid[row][col] == 'X' || grid[row][col] == 'O')
    {
        return true;
    }

    return false;
}

// ------------------------------------------------
// ------------ Enter Choice Function
void Board::enterChoice(int position, char ch)
{
    int row = (position - 1) / 3;
    int col = (position - 1) % 3;

    grid[row][col] = ch;
}

// ------------------------------------------------
// ------------ Is Board Full Function
bool Board::isfull()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (grid[i][j] != 'X' || grid[i][j] != 'O')
            {
                return false;
            }
        }
    }

    return true;
}

// ------------------------------------------------
// ------------ Check Winner Function
char Board::winner()
{
    for (int i = 0; i < 3; i++)
    {
        if (grid[0][i] == grid[1][i] && grid[1][i] == grid[2][i])
        {
            return grid[1][i];
        }
        if (grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2])
        {
            return grid[i][1];
        }
    }

    if (grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2])
    {
        return grid[1][1];
    }
    if (grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0])
    {
        return grid[1][1];
    }

    return 'N';
}

// =================================================
// ================== TicTacToe Method ==================
// =================================================

// ------------ Constructor Function
TicTacToe::TicTacToe()
{
    string sql = "CREATE TABLE IF NOT EXISTS TicTacToeScores(ID INTEGER PRIMARY KEY AUTOINCREMENT,USER_SCORE INT NOT NULL,COMP_SCORE INT NOT NULL);";
    gameDB = new DB("../db/TicTacToe.db", sql);
    gameBoard.display(win, loss);
    getScore();
}

// ------------------------------------------------
// ------------ Get Score Function
void TicTacToe::getScore()
{
    string sql = "SELECT USER_SCORE, COMP_SCORE FROM TicTacToeScores ORDER BY ID DESC LIMIT 1;";
    gameDB->executeSQL(sql, [](void *data, int argc, char **argv, char **azColName) -> int {
        TicTacToe* game = static_cast<TicTacToe*>(data);
        
        if (game && argc >= 2 && argv[0] && argv[1])
        {
            // 3. Convert string to int and save to class members
            game->win = std::stoi(argv[0]);
            game->loss = std::stoi(argv[1]);
        }

        return 0;
    }, this);
}

// ------------------------------------------------
// ------------ Set Score Function
void TicTacToe::setScore()
{
    string sql = "INSERT INTO TicTacToeScores (USER_SCORE, COMP_SCORE) VALUES (" + to_string(win) + ", " + to_string(loss) + ");";
    gameDB->executeSQL(sql, [](void *data, int argc, char **argv, char **azColName) -> int
    { 
        return 0; 
    }, nullptr);

    cout << GREEN << "Score saved to database!" << RESET << endl;
}

// ------------------------------------------------
// ------------ Get User Choice Function
void TicTacToe::getUserChoice()
{
    int choice;

    while (true)
    {

        cout << "Enter your choice : ";

        if (!(cin >> choice))
        {
            cout << "Invalid, That's not a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (choice < 1 || choice > 9)
        {
            cout << "Invalid choices!\n";
            continue;
        }
        else if (gameBoard.isOccupied(choice))
        {
            cout << "Invalid: Choice alreay taken!\n";
            continue;
        }
        else
        {
            gameBoard.enterChoice(choice, 'X');
            break;
        }
    }
}

// ------------------------------------------------
// ------------ Get Computer Choice Function
void TicTacToe::getBotsChoice()
{
    cout << "Bot is thinking...\n";
    h.delay(1);

    while (true)
    {
        int botChoice = h.randomNUmber(9);

        if (!gameBoard.isOccupied(botChoice))
        {
            gameBoard.enterChoice(botChoice, 'O');
            break;
        }
    }
}

// ------------------------------------------------
// ------------ Input Move Function
void TicTacToe::inputMove()
{
    int playerTurn = false;

    while (!gameBoard.isfull() && gameBoard.winner() == 'N')
    {
        h.clearScreen();

        cout << CYAN
             << "=======================================" << "\n";
        cout << "  || " << B_RED << "   TIC    " << B_GREEN << "   TAC    " << B_BLUE << "   TOE    " << CYAN << "||" << "\n";
        cout << "======================================="
             << RESET;

        gameBoard.display(win, loss);

        if (playerTurn)
        {
            getUserChoice();
        }
        else
        {
            getBotsChoice();
        }

        playerTurn = !playerTurn;
    }
}

// ------------------------------------------------
// ------------ Show Result Function
void TicTacToe::showResult()
{
    int result = gameBoard.winner();
    h.clearScreen();
    if (result == 'X')
    {
        cout << B_GREEN << "***************************************\n";
        cout << "* " << B_CYAN << "        VICTORY!   YOU WON         " << B_GREEN << " *\n";
        cout << "***************************************"
             << RESET;
        win++;
    }
    else if (result == 'O')
    {
        cout << B_RED << "=======================================\n";
        cout << "|| " << RED << "    DEFEAT!   COMPUTER WINS!     " << B_RED << " ||\n";
        cout << "======================================="
             << RESET;
        loss++;
    }
    else
    {
        cout << B_MAGENTA << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "| " << YELLOW << "      STALEMATE! IT'S A DRAW      " << B_MAGENTA << " |\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
             << RESET;
    }

    gameBoard.display(win, loss);
    gameBoard.reset();
}

// ------------------------------------------------
// ------------ Play Function
void TicTacToe::play()
{
    char ch;

    while (true)
    {
        inputMove();
        showResult();
        setScore();
        cout << "Do you want to Quit (Yes(Y) || NO(N)) : ";
        cin >> ch;

        if (ch == 'Y' || ch == 'y')
        {
            break;
        }
    }
}