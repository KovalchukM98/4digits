#ifndef MENU_H
#define MENU_H

#include "game.h"
#include "leaderboard.h"
#include <string>
class Menu {
public:
    Menu();

    ~Menu();

    int join();

    bool is_menu_input_valid(std::string str);

    bool is_settings_input_valid(std::string str);

    void start();

    void settings();

    void about();

private:
    int lenght;
    Game* game;
    Leaderboard* leaderboard;
};

#endif