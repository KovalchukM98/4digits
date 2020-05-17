#ifndef MENU_H
#define MENU_H

#include "game.h"
#include "leaderboard.h"
#include <fstream>
#include <iostream>
#include <string>
class Menu {
public:
    Menu();

    ~Menu();

    int join();

    bool is_input_valid(std::string str, int minValid, int maxValid);

    void start();

    void settings();

    void about();

private:
    int lenght;
    // Game game;
    Leaderboard leaderboard;
};

#endif