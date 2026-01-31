#ifndef HELPER_H
#define HELPER_H

#include <iostream>
#include <cstdlib>
#include <thread>
#include <chrono>
#include <ctime>

// Text Styles
#define RESET "\033[0m"
#define BOLD "\033[1m"
#define UNDERLINE "\033[4m"

// Foreground Colors (Regular)
#define BLACK "\033[30m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"

// Foreground Colors (Bright/Bold)
#define B_BLACK "\033[1;30m"
#define B_RED "\033[1;31m"
#define B_GREEN "\033[1;32m"
#define B_YELLOW "\033[1;33m"
#define B_BLUE "\033[1;34m"
#define B_MAGENTA "\033[1;35m"
#define B_CYAN "\033[1;36m"
#define B_WHITE "\033[1;37m"

// Background Colors
#define BG_BLACK "\033[40m"
#define BG_RED "\033[41m"
#define BG_GREEN "\033[42m"
#define BG_YELLOW "\033[43m"
#define BG_BLUE "\033[44m"
#define BG_MAGENTA "\033[45m"
#define BG_CYAN "\033[46m"
#define BG_WHITE "\033[47m"

// Helper Class
class Helper
{
public:
    void delay(int);
    void clearScreen();
    int randomNUmber(int);
};

#endif