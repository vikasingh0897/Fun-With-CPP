#include "../include/Helper.h"

using namespace std;

// ------------------------------------------------
// ------------ Randon Number Function
int Helper::randomNUmber(int max)
{
    srand(time(0));

    return ((rand() % max) + 1);
}

// ------------------------------------------------
// ------------ Clear Screen Function
void Helper::clearScreen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// ------------------------------------------------
// ------------ Delay Function
void Helper::delay(int time)
{
    this_thread::sleep_for(chrono::seconds(time));
}